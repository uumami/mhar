import torch


def create_projection_matrix(ae,
                             device='cpu',
                             check=True):
    """
    Creates the projection matrix  I - A'(A A')^(-1)A (n x n)
    -------------
    :param ae:  Pytorch Tensor (Single, Double) / Pytorch CUDA Tensor (Single/Double)
                Equality Restriction Matrix
    :param device:  String, default = cpu
                    Hardware used to make the computations and allocate the result.
                    If equal to cpu then the CPUs are used for computing the inverse.
                    If equal to cuda then the a GPU is used for computing the inverse.
    :param check:   Boolean, default= True
                    If True the error term for the Inverse matrix is computed using the
                    infinity-norm (max)
    -------------
    :return:    Torch Tensor
                Contains the Projection Matrix. In the cpu or the gpu, depending on the
                device value.
    """

    # Compute (A A')^(-1)
    aet = torch.transpose(ae, 0, 1)
    ae_aux = torch.matmul(ae, aet)
    ae_inv = torch.inverse(ae_aux)

    # Check numerical stability of (A A')^(-1)
    if check:
        est = torch.mm(ae_inv, ae_aux)
        est = torch.max(torch.abs(est - torch.eye(est.shape[0], device=device)))
        print('Max non zero error: ', est)
        del est

    # Compute I - A'(A A')^(-1)A
    la = torch.matmul(aet, ae_inv)
    projection_matrix = torch.matmul(la, ae)
    projection_matrix = torch.eye(projection_matrix.shape[0], device=device) - projection_matrix

    # Free Memory
    del ae_aux
    del ae_inv
    del la

    return projection_matrix
