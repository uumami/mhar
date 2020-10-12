import torch
from mhar.projection_matrix import create_projection_matrix
from mhar.random_generator import create_h, draw_uniform

def walk(z,
              ai=torch.empty(0),
              bi=torch.empty(0),
              ae=torch.empty(0),
              be=torch.empty(0),
              x_0=torch.empty(0),
              T=1,
              device='cpu',
              warm=0,
              seed=None,
              thinning=None,
              check=True,
              save=True):
    '''
    :param z:   int
                padding parameter
    :param ai: torch tensor
                AI:=Coefficients of Inequality Restrictions
    :param bi: torch tensor
                bi:=Restriction values of the Inequality Restrictions
    :param ae: torch tensor
                AE:=Coefficients of Equality Restrictions
    :param be: torch tensor
                bi:= Restriction values of the Equality Restrictions
    :param x_0: torch tensor
                Starting point, must be strict inner point
    :param T:   int
                iid-iterations, total_iid_points = T*z. Each iid iteration will burn
                the samples established by the thinning factor.
    :param warm: int
                Number of iid-iterations needed to warm.
    :param seed: int
                random seed
    :param thinning: int
                    Thinning Factor. Default O(n^3)
    :param check: bool
                    Print for sanity check
    :param save: bool
                Save iid samples or drop them, for debugging.
    :param device: string
                    cpu or cuda
    :return: int or torch tensor

    '''
    # Assert the device is correctly specified
    assert device in ['cpu', 'cuda'], print('The device is not correctly specified: ', device,
                                            '\n Please choose cpu or cuda')

    # Set min and max values
    min_ = torch.finfo(torch.get_default_dtype()).min + 2.0
    max_ = torch.finfo(torch.get_default_dtype()).max - 2.0

    # Set seed
    random_gen = torch.Generator(device=device)
    if seed:
        random_gen.manual_seed(seed)
    else:
        random_gen.seed()

    # Get dimensions
    n = ai.shape[1]
    mi = ai.shape[0]
    me = ae.shape[0]
    print('n: ', n, '  mi:', mi, '  me:', me, '  z:', z)

    # Check if the polytope is full dimensional
    non_full = me > 0

    # Set thinning factor
    if thinning:
        pass
    else:
        if me == 0:
            thinning = int(n * n * n)
        else:
            thinning = int((n - 1) * (n - 1) * (n - 1))
        print('Automatic Thinning factor: ', thinning)

    # Copy tensors to gpu
    if 'cpu' not in str(device):
        ai = ai.cuda()
        bi = bi.cuda()
        x = x_0.cuda()
        if non_full:
            ae = ae.cuda()
    else:
        x = x_0

    # Create projection matrix
    if non_full:
        projection = create_projection_matrix(ae, device, check)

    # Pad Matrix
    x = x.repeat(z, 1, 1)

    # Iteration Loop
    t = 1
    burned = 0
    while t <= T:

        # Draw direction
        h = create_h(n, z, generator=random_gen, device=device)

        # Project
        if non_full:
            d = torch.matmul(projection, h)
        else:
            d = h

        # Compute B - AX / AD
        numerator = bi - torch.matmul(ai, x)
        denominator = torch.matmul(ai, d)
        # Overwrite numerator to keep memory free
        numerator = numerator / denominator
        # From the positive denominators you want the smallest one
        lambda_pos = torch.min(~(denominator > 0.0) * max_ +
                               (denominator > 0.0) * numerator, 1).values
        # From the negative denominators you want the biggest
        lambda_neg = torch.max(~(denominator < 0.0) * min_ +
                               (denominator < 0.0) * numerator, 1).values
        # Uniform draw
        u = draw_uniform(z, generator=random_gen, device=device)
        theta = (1.0 - u) * lambda_pos + u * lambda_neg

        # New X
        x = x + d * theta[:, None]

        # Warm
        if (warm > 0) & (burned >= thinning):
            warm = warm - 1
            burned = 0

        # Manage the burning rate and save points
        if burned >= thinning:
            if (t == 1) & save:
                X = torch.flatten(x, start_dim=1)
                if device == 'cuda':
                    X = X.cpu()
            if (t > 1) & save:
                X = torch.cat((X,
                               torch.flatten(x, start_dim=1).cpu()),
                              dim=0)
            t = t + 1
            burned = 0

        burned = burned + 1

        # Return
    if save:
        return X
    else:
        return 0
