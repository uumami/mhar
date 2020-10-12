import torch
import numpy as np
import time
from mhar.mhar import walk


def create_simplex(n):
    """
    Cretes the restrictions and innerpoint for a simplex polytope

    :param n: int
    Space of the polytope

    :return: Torch tensor representing the restrictions and innerpoint that form the simplex in Rn
    """
    # Create Inequalities
    simplex_ai = torch.eye(n) * -1.0
    simplex_bi = torch.empty(n, 1, dtype=torch.get_default_dtype())
    simplex_bi.fill_(0.0)

    # Create Equalities
    simplex_ae = torch.empty(1, n, dtype=torch.get_default_dtype())
    simplex_ae.fill_(1.0)
    simplex_be = torch.empty(1, 1, dtype=torch.get_default_dtype())
    simplex_be.fill_(1.0)

    # Create Innerpoint
    x_0 = torch.empty(n, 1, dtype=torch.get_default_dtype())
    x_0.fill_(1.0 / n)
    return simplex_ai, simplex_bi, simplex_ae, simplex_be, x_0


def create_hypercube(n):
    """
    Cretes the restrictions and innerpoint for an hypercube polytope in [-1,1]^n

    :param n: int
    Space of the polytope

    :return: Torch tensor representing the restrictions and innerpoint that form the
    hypercube in [-1.1]^n
    """
    # Create Inequalities
    hyper_ai = torch.cat((torch.eye(n), torch.eye(n) * -1.0), dim=0)
    hyper_bi = torch.from_numpy(np.array([1] * 2 * n))[:, None]
    x_0 = torch.empty(n, 1, dtype=torch.get_default_dtype())
    x_0.fill_(0.01)
    return hyper_ai, hyper_bi, x_0


def hypercube_test(n,
                   z=1,
                   thinning=None,
                   device='cpu',
                   save=True,
                   T=1,
                   warm=0,
                   seed=1693):
    # Init hypercube
    hyper_ai, hyper_bi, x_0 = create_hypercube(n)
    start_time = time.time()
    # Automatic Thinning Factor
    if not thinning:
        thinning = n*n*n
    # Sample Hypercube
    X = walk(z=z,
                  ai=hyper_ai,
                  bi=hyper_bi,
                  x_0=x_0,
                  seed=seed,
                  check=True,
                  T=T,
                  warm=warm,
                  thinning=thinning,
                  device=device,
                  save=save)
    time_ = (time.time() - start_time)
    return X, time_


def simplex_test(n,
                  z=1,
                  thinning=None,
                  device='cpu',
                  save=True,
                  T=1,
                  warm=0,
                  seed=17283):
    # Init Simplex
    simplex_ai, simplex_bi, simplex_ae, simplex_be, x_0 = create_simplex(n)
    start_time = time.time()
    # Automatic Thinning
    if not thinning:
        thinning = n*n*n
    X = walk(z=z,
                  ai=simplex_ai,
                  bi=simplex_bi,
                  ae=simplex_ae,
                  be=simplex_be,
                  x_0=x_0,
                  seed=seed,
                  check=True,
                  T=T,
                  warm=warm,
                  thinning=thinning,
                  device=device,
                  save=save)
    time_ = (time.time() - start_time)
    return X, time_
