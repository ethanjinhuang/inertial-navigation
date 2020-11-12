import numpy as np
from numpy import sin, cos, arctan2, arcsin


# 将 欧拉角 转换为 方向余弦阵
def ea2dcm(euler_angle):
    phi = euler_angle[0]
    theta = euler_angle[1]
    gamma = euler_angle[2]
    result = np.empty([3, 3], dtype=float)
    # line 1
    result[0, 0] = np.cos(phi) * cos(gamma) - sin(phi) * sin(theta) * sin(gamma)
    result[0, 1] = -sin(phi) * cos(theta)
    result[0, 2] = cos(phi) * sin(gamma) + sin(phi) * sin(theta) * cos(gamma)
    # line 2
    result[1, 0] = sin(phi) * cos(gamma) + cos(phi) * sin(theta) * sin(gamma)
    result[1, 1] = cos(phi) * cos(theta)
    result[1, 2] = sin(phi) * sin(gamma) - cos(phi) * sin(theta) * cos(gamma)
    # line 3
    result[2, 0] = -cos(theta) * sin(gamma)
    result[2, 1] = sin(theta)
    result[2, 2] = cos(theta) * cos(gamma)
    return result


# 将 欧拉角 转换为 四元数
def ea2qv(euler_angle):
    result = np.empty([4], dtype=float)
    h_phi = euler_angle[0] / 2
    h_theta = euler_angle[1] / 2
    h_gamma = euler_angle[2] / 2
    result[0] = cos(h_phi) * cos(h_theta) * cos(h_gamma) - sin(h_phi) * sin(h_theta) * sin(h_theta)
    result[1] = cos(h_phi) * sin(h_theta) * cos(h_gamma) - sin(h_phi) * cos(h_theta) * sin(h_theta)
    result[2] = sin(h_phi) * sin(h_theta) * cos(h_gamma) + cos(h_phi) * cos(h_theta) * sin(h_theta)
    result[3] = sin(h_phi) * cos(h_theta) * cos(h_gamma) - cos(h_phi) * sin(h_theta) * sin(h_theta)
    return result


# 将 方向余弦阵 转换为 欧拉角
def dcm2ea(direct_cosine_matrix):
    result = np.empty([3], dtype=float)
    result[1] = arcsin(direct_cosine_matrix[2, 1])
    if abs(direct_cosine_matrix[2, 1]) <= 0.999999:
        result[0] = -arctan2(direct_cosine_matrix[0, 1], direct_cosine_matrix[1, 1])
        result[2] = -arctan2(direct_cosine_matrix[2, 0], direct_cosine_matrix[2, 2])
    else:
        result[0] = 0
        result[2] = arctan2(direct_cosine_matrix[0, 2], direct_cosine_matrix[0, 0])
    return result

