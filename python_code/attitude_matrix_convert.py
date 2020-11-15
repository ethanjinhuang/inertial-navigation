import numpy as np
from numpy import sin, cos, arctan2, arcsin, arccos, sqrt


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


# 将 方向余弦阵 转换为 四元数
def dcm2qv(dcm):
    qv = np.empty([4], dtype=float)
    c11 = dcm[0, 0]
    c12 = dcm[0, 1]
    c13 = dcm[0, 2]
    c21 = dcm[1, 0]
    c22 = dcm[1, 1]
    c23 = dcm[1, 2]
    c31 = dcm[2, 0]
    c32 = dcm[2, 1]
    c33 = dcm[2, 2]
    if c11 >= c22 + c33:
        qv[1] = 0.5 * sqrt(1 + c11 - c22 - c33)
        qv[0] = (c32 - c23) / (4 * qv[1])
        qv[2] = (c12 + c21) / (4 * qv[1])
        qv[3] = (c13 + c31) / (4 * qv[1])
    elif c22 >= c11 + c33:
        qv[2] = 0.5 * sqrt(1 - c11 + c22 - c33)
        qv[0] = (c13 - c31) / (4 * qv[2])
        qv[1] = (c12 + c21) / (4 * qv[2])
        qv[3] = (c23 + c32) / (4 * qv[2])

    elif c33 >= c11 + c22:
        qv[3] = 0.5 * sqrt(1 - c11 - c22 + c33)
        qv[0] = (c21 - c12) / (4 * qv[3])
        qv[1] = (c13 + c31) / (4 * qv[3])
        qv[2] = (c23 + c32) / (4 * qv[3])
    else:
        qv[0] = 0.5 * sqrt(1 + c11 + c22 + c33)
        qv[1] = (c32 - c23) / (4 * qv[0])
        qv[2] = (c13 + c31) / (4 * qv[0])
        qv[3] = (c21 + c12) / (4 * qv[0])

    return qv


# 将 四元数 转换为 欧拉角
def qv2ea(qv):
    ea = np.empty([3], dtype=float)
    q0 = qv[0]
    q1 = qv[1]
    q2 = qv[2]
    q3 = qv[3]
    ea[1] = arcsin(2 * (q2 * q3 + q0 * q1))
    if abs(2 * (q2 * q3 + q0 * q1)) <= 0.999999:
        ea[2] = -arctan2(2 * (q1 * q3 - q0 * q2), (q0 * q0 - q1 * q1 - q2 * q2 + q3 * q3))
        ea[0] = -arctan2(2 * (q1 * q2 - q0 * q3), (q0 * q0 - q1 * q1 + q2 * q2 - q3 * q3))
    else:
        ea[2] = arctan2(2 * (q1 * q3 + q0 * q2), (q0 * q0 + q1 * q1 - q2 * q2 - q3 * q3))
        ea[0] = 0
    return ea


# 将 四元数 转换为 方向余弦阵
def qv2dcm(qv):
    dcm = np.empty([3, 3], dtype=float)
    dcm[0, 0] = qv[0] * qv[0] + qv[1] * qv[1] - qv[2] * qv[2] - qv[3] * qv[3]
    dcm[0, 1] = 2 * (qv[1] * qv[2] - qv[0] * qv[3])
    dcm[0, 2] = 2 * (qv[1] * qv[3] + qv[0] * qv[2])
    dcm[1, 0] = 2 * (qv[1] * qv[2] + qv[0] * qv[3])
    dcm[1, 1] = qv[0] * qv[0] - qv[1] * qv[1] + qv[2] * qv[2] - qv[3] * qv[3]
    dcm[1, 2] = 2 * (qv[2] * qv[3] - qv[0] * qv[1])
    dcm[2, 0] = 2 * (qv[1] * qv[3] - qv[0] * qv[2])
    dcm[2, 1] = 2 * (qv[2] * qv[3] + qv[0] * qv[1])
    dcm[2, 2] = qv[0] * qv[0] - qv[1] * qv[1] - qv[2] * qv[2] + qv[3] * qv[3]

    return dcm


# 将 四元数 转换为 等效旋转矢量
def qv2erv(qv):
    erv = np.empty([3], dtype=float)
    if qv[0] < 0:
        qv = -qv

    hnorm = arccos(qv[0])
    b = 0
    if hnorm > 1.e-20:
        b = 2 * hnorm / sin(hnorm)
    else:
        b = 2

    erv = [b * qv[1], b * qv[2], b * qv[3]]
    return erv


# 将 等效旋转矢量 转化为 四元数
def erv2qv(erv):
    qv = np.empty([4], dtype=float)
    nperv = np.array(erv)
    norm = sum(nperv * nperv)
    temp = 0
    if norm < 1.e-8:

        qv[0] = 1 - norm * (1.0 / 8 - norm / 384)
        temp = 0.5 - norm * (1.0 / 48 - norm / 3840)

    else:

        norm = sqrt(norm)
        qv[0] = cos(norm / 2)
        temp = sin(norm / 2) / norm

        qv[1] = temp * nperv[0]
        qv[2] = temp * nperv[1]
        qv[3] = temp * nperv[2]
        return qv


# 将 欧拉角 转换为 等效旋转矢量
def ea2erv(ea):
    qv = erv2qv(ea)
    erv = qv2erv(qv)
    return erv


# 将 方向余弦阵 转换为 等效旋转矢量
def dcm2erv(dcm):
    qv = dcm2qv(dcm)
    erv = qv2erv(qv)
    return erv


# 将 等效旋转矢量 转化为 方向余弦阵
def erv2dcm(erv):
    qv = erv2qv(erv)
    dcm = qv2dcm(qv)
    return dcm


# 将 等效旋转矢量 转化为 欧拉角
def erv2ea(erv):
    qv = erv2qv(erv)
    ea = qv2ea(qv)
    return ea
