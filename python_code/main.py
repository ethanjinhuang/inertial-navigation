from attitude_matrix_convert import *
import numpy as np

ea = np.ones([3], dtype=float, order='C')
print(ea2dcm(ea))
dcm = ea2dcm(ea)
print(dcm2ea(dcm))
