import numpy as np
import torch
import os

delimiter = ','
folder = '/mnt/5AE83504E834DFC5/matrices'
restrictions={'A_eq':'A_eq', 'b_eq':'b_eq', 'A_in':'A_in', 'b_in':'b_in'}


def read_restrictions(folder='', delimiter=',', restrictions={
    'A_eq':'A_eq', 'b_eq':'b_eq', 'A_in':'A_in', 'b_in':'b_in'}, np_type=np.float64):

    # Add / at the end of the path
    if folder[-1] != '/':
        folder += '/'

    matrices = [f for f in os.listdir(folder)]

    # A_eq
    A_eq = None
    b_eq = None
    A_in = None
    b_in = None

    for m in matrices:
        if restrictions['A_eq'] in m:
            A_eq = np.loadtxt(folder + m, dtype=np_type, delimiter=delimiter, ndmin=2)
    # b_eq
    for m in matrices:
        if restrictions['b_eq'] in m:
            b_eq = np.loadtxt(folder + m, dtype=np_type, delimiter=delimiter, ndmin=2)
    # A_in
    for m in matrices:
        if restrictions['A_in'] in m:
            A_in = np.loadtxt(folder + m, dtype=np_type, delimiter=delimiter, ndmin=2)
    # b_in
    for m in matrices:
        if restrictions['b_in'] in m:
            b_in = np.loadtxt(folder + m, dtype=np_type, delimiter=delimiter, ndmin=2)

    return A_in, b_in, A_eq, b_eq


def read_x0(folder='', delimiter=',', prefix='', np_type=np.float64):

    # Add / at the end of the path
    if folder[-1] != '/':
        folder += '/'
    matrices = [f for f in os.listdir(folder)]

    for m in matrices:
        if prefix in m:
            x0 = np.loadtxt(folder + m, dtype=np_type, delimiter=delimiter, ndmin=2)
    return x0


def np_2_tensor(A_in = None, b_in=None, A_eq=None, b_eq=None, x0=None):

    torch_type = torch.get_default_dtype()

    if A_eq is None:
        A_eq = torch.empty(0, dtype=torch_type)
    else:
        A_eq = torch.tensor(A_eq, dtype=torch_type)

    if b_eq is None:
        b_eq = torch.empty(0, dtype=torch_type)
    else:
        b_eq = torch.tensor(b_eq, dtype=torch_type)

    if A_in is None:
        print('A_in is None')
    if b_in is None:
        print('b_in is None')
    if x0 is None:
        print('x0 is None')

    A_in = torch.tensor(A_in, dtype=torch_type)
    b_in = torch.tensor(b_in, dtype=torch_type)
    x0 = torch.tensor(x0, dtype=torch_type)
    
    return A_in, b_in, A_eq, b_eq, x0


def mhar_tensors(restrictions, starting_point):
    tensors = np_2_tensor(A_in=restrictions[0], b_in=restrictions[1],
                                        A_eq=restrictions[2], b_eq=restrictions[3],
                                        x0=starting_point)
    return tensors

