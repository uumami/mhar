import torch
from mhar.classic_polytopes import hypercube_test, simplex_test

def mhar_example():
    # Set float 64 as default precision, can be changed to 32
    torch.set_default_dtype(torch.float64)
    # setting device on GPU if available, else CPU
    device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
    print('Using device:', device)
    device_ = device.type

    # Hypercube
    X, time_ = hypercube_test(n=3,
                              z=3,
                              device=device_,
                              save=True,
                              T=100,
                              seed=1693)
    print('Hypercube')
    print(X.shape, time_)
    print("-----------------------------------")

    # Simplex
    X, time_ = simplex_test(n=3,
                            z=5,
                            device=device_,
                            save=True,
                            T=100,
                            seed=1693)
    print('Simplex')
    print(X.shape, time_)

