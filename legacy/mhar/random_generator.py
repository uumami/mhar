import torch

def create_h(n,
             z,
             generator,
             device='cpu'):
    """
    Creates a Tensor (z x n x 1) where each entry ~ N(0,1). Automatically detects the
    precision 64 bits or 32 bits.
    -------------
    :param n:   int
                Dimension of the Space where the Polytope Lives
    :param z:   int
                Padding Parameter
    :param generator:
    :param device:  String, default = cpu
                    Hardware used to make the computations and allocate the result.
                    If equal to cpu then the CPUs are used for computing the inverse.
                    If equal to cuda then the a GPU is used for computing the inverse.
    -------------
    :return:    Torch Tensor
                Tensor (z x n x 1) where each entry ~ N(0,1)Contains a tensor

    """
    if '64' in str(torch.get_default_dtype()):
        if 'cuda' == device:
            h = torch.cuda.DoubleTensor(z, n, 1).normal_(generator=generator)
        elif 'cpu' == device:
            h = torch.DoubleTensor(z, n, 1).normal_(generator=generator)
    else:
        if 'cuda' == device:
            h = torch.cuda.FloatTensor(z, n, 1).normal_(generator=generator)
        elif 'cpu' == device:
            h = torch.FloatTensor(z, n, 1).normal_(generator=generator)

    return h

def draw_uniform(z, generator,device='cpu'):
    """
    Creates a tensor (z x 1) where each entry ~ U(0,1). Automatically detects the
    precision 64 bits or 32 bits.
    -------------
    :param n:   int
                Dimension of the Space where the Polytope Lives
    :param z:   int
                Padding Parameter
    :param generator:
    :param device:  String, default = cpu
                    Hardware used to make the computations and allocate the result.
                    If equal to cpu then the CPUs are used for computing the inverse.
                    If equal to cuda then the a GPU is used for computing the inverse.
    -------------
    :return:    Torch Tensor
                Tensor (z x 1) where each entry ~ U(0,1)

    """

    if '64' in str(torch.get_default_dtype()):
        if 'cuda' == device:
            h = torch.cuda.DoubleTensor(z, 1).uniform_(generator=generator)
        elif 'cpu' == device:
            h = torch.DoubleTensor(z, 1).uniform_(generator=generator)
    else:
        if 'cuda' == device:
            h = torch.cuda.FloatTensor(z, 1).uniform_(generator=generator)
        elif 'cpu' == device:
            h = torch.FloatTensor(z, 1).uniform_(generator=generator)
    return h
