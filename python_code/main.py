from attitude_matrix_convert import *
import numpy as np

ea = np.ones([3], dtype=float, order='C')
print(ea)
print(ea2dcm(ea))
dcm = ea2dcm(ea)
print(dcm2ea(dcm))
qv = dcm2qv(dcm)
print(qv)
erv = qv2erv(qv)
print(erv)
ea = erv2ea(erv)
print(ea)