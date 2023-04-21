from scipy.optimize import linprog
import numpy as np

def chebyshev_center(A_in, b_in, A_eq = None, b_eq = None, lb = None, ub = None,
                     np_type=np.float64):

        # The equality restrictions have zero norm
        A_in_norm = np.matrix(np.sum(A_in ** 2., axis=-1) ** (1. / 2.), dtype=np_type)
        # Create new restriction matrices
        A_in_norm = np.concatenate((A_in, A_in_norm.transpose()), axis=1)

        # Equality restrictions exist
        try:
                eq = A_eq.shape[0]
        except:
                eq = 0
        if eq:
                # The equality restrictions have zero norm. Is transposed to keep order
                A_eq_norm = np.zeros((1, A_eq.shape[0]), dtype=np_type)
                # Create new restriction matrices
                A_eq_norm = np.concatenate((A_eq, A_eq_norm.transpose()), axis=1)
        else:
                A_eq_norm = None

        # Create c
        c = np.concatenate((np.zeros(A_in.shape[1], dtype=np_type), [-1.]))

        r = linprog(c=c,
                A_ub=A_in_norm,
                b_ub=b_in,
                A_eq=A_eq_norm,
                b_eq=b_eq,
                bounds = (lb, ub),
                method= 'revised simplex')

        status = {0:'Optimization proceeding nominally.',
                  1: 'Iteration limit reached.',
                  2: 'Problem appears to be infeasible.',
                  3: ' Problem appears to be unbounded.',
                  4: ' Numerical difficulties encountered.',
                }[r.status]
        print('\nSimplex Status for the Chebyshev Center\n', status)
        
        return np.array(r.x[:-1], ndmin=2).transpose()


def starting_point(restrictions, np_type=np.float64, lb=None, ub=None):

        x0 = chebyshev_center(A_in=restrictions[0], b_in=restrictions[1],
                              A_eq=restrictions[2], b_eq=restrictions[3],
                              lb=lb, ub=ub,
                              np_type=np_type)
        return x0


