/*
*************************************************************************************
*file:	attitude_matrix.cpp
*@Description:	存放attitude_matrix.h中类成员函数
*creator：Jin Huang
*organization:sdust
*e-mail:kim.huang.j@qq.com
*datetime：//2020
*************************************************************************************
*/
#include"attitude_matrix.h"

// 创建用于交换的临时对象。
Euler_angle ea_temp;
Direct_cosine_matrix dcm_temp;
Quaternion_vector qv_temp;

// ==========================================Euler Start==========================================

Euler_angle::Euler_angle(double phi, double theta, double gamma)
{
    value[0] = phi; value[1] = theta; value[2] = gamma;
}

Euler_angle::Euler_angle(Vector3d inputvector)
{
    value = inputvector;
}

void Euler_angle::show()
{
    cout << value << endl;
}

void Euler_angle::operator<<(Vector3d input)
{
    if (input.size() != 3) { cerr << "The Vector3d for Euler_angle is wrong." << endl, exit(0); }
    for (int i = 0; i < 3; i++)
    {
        value(i) = input(i);
    }
}

void Euler_angle::operator=(Euler_angle input)
{
    this->value = input.value;
}

//Euler_angle Euler_angle::operator*(Euler_angle& input)
//{
//	ea_temp.initialize();
//	ea_temp.value = this->value * input.value;
//	return ea_temp;
//}

Euler_angle Euler_angle::operator+(Euler_angle& input)
{
    ea_temp.initialize();
    ea_temp.value = this->value + input.value;
    return ea_temp;
}

// ======欧拉角计算函数======
// 欧拉角计算反对称阵ssm
Matrix3d Euler_angle::EA2ssm()
{
    Matrix3d res = Eigen::Matrix3d::Zero();
    res(0, 1) = -value(2); res(0, 2) = value(1);
    res(1, 0) = value(2); res(1, 2) = -value(0);
    res(2, 0) = -value(1); res(2, 1) = value(0);
    // cout << res << endl;
    return res;
}

// 欧拉角 --> 方向余弦阵
Matrix3d Euler_angle::EA2DCM()
{
    Matrix3d result = Eigen::Matrix3d::Zero();
    double phi = value(0), theta = value(1), gamma = value(2);
    //method 1
    // line 1
    result(0, 0) = cos(phi) * cos(gamma) - sin(phi) * sin(theta) * sin(gamma);
    result(0, 1) = -sin(phi) * cos(theta);
    result(0, 2) = cos(phi) * sin(gamma) + sin(phi) * sin(theta) * cos(gamma);
    // line 2
    result(1, 0) = sin(phi) * cos(gamma) + cos(phi) * sin(theta) * sin(gamma);
    result(1, 1) = cos(phi) * cos(theta);
    result(1, 2) = sin(phi) * sin(gamma) - cos(phi) * sin(theta) * cos(gamma);
    // line 3
    result(2, 0) = -cos(theta) * sin(gamma);
    result(2, 1) = sin(theta);
    result(2, 2) = cos(theta) * cos(gamma);
    return result;
}

// 欧拉角 --> 四元数
Vector4d Euler_angle::EA2QV()
{
    Vector4d result = Eigen::Vector4d::Zero();
    double hphi = value(0) / 2;
    double htheta = value(1) / 2;
    double hgamma = value(2) / 2;
    result(0) = cos(hphi) * cos(htheta) * cos(hgamma) - sin(hphi) * sin(htheta) * sin(htheta);
    result(1) = cos(hphi) * sin(htheta) * cos(hgamma) - sin(hphi) * cos(htheta) * sin(htheta);
    result(2) = sin(hphi) * sin(htheta) * cos(hgamma) + cos(hphi) * cos(htheta) * sin(htheta);
    result(3) = sin(hphi) * cos(htheta) * cos(hgamma) - cos(hphi) * sin(htheta) * sin(htheta);
    return result;
}

// 欧拉角 --> 等效旋转矢量
Vector3d Euler_angle::EA2ERV()
{
    Quaternion_vector qv(this->EA2QV());
    return qv.QV2ERV();
}

// ========================================== Euler End ===========================================

// ==========================================Direct cosine matrix Start==========================================

Direct_cosine_matrix::Direct_cosine_matrix(Matrix3d input_matrix)
{
    value = input_matrix;
}

void Direct_cosine_matrix::operator<<(Matrix3d matrix3)
{
    if (matrix3.size() != 9) { cerr << "The Matrix3d for Direct_cosine_matrix is wrong." << endl, exit(0); }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            value(i, j) = matrix3(i, j);
        }
    }
}

void Direct_cosine_matrix::operator=(Direct_cosine_matrix input)
{
    this->value = input.value;
}

// 方向余弦阵 --> 欧拉角
Vector3d Direct_cosine_matrix::DCM2EA()
{
    Vector3d result = Eigen::Vector3d::Zero();
    result(1) = asin(value(2, 1));
    if (abs(value(2, 1)) <= 0.999999)
    {
        result(0) = -atan2(value(0, 1), value(1, 1));
        result(2) = -atan2(value(2, 0), value(2, 2));
    }
    else
    {
        result(0) = 0;
        result(2) = atan2(value(0, 2), value(0, 0));
    }
    return result;
}

// 方向余弦阵--> 四元数
Vector4d Direct_cosine_matrix::DCM2QV()
{
    Vector4d result = Eigen::Vector4d::Zero();
    double c11 = value(0, 0), c12 = value(0, 1), c13 = value(0, 2);
    double c21 = value(1, 0), c22 = value(1, 1), c23 = value(1, 2);
    double c31 = value(2, 0), c32 = value(2, 1), c33 = value(2, 2);
    if (c11 >= c22 + c33)
        result(1) = 0.5 * sqrt(1 + c11 - c22 - c33), result(0) = (c32 - c23) / (4 * result(1)), result(2) = (c12 + c21) / (4 * result(1)), result(3) = (c13 + c31) / (4 * result(1));
    else if (c22 >= c11 + c33)
        result(2) = 0.5 * sqrt(1 - c11 + c22 - c33), result(0) = (c13 - c31) / (4 * result(2)), result(1) = (c12 + c21) / (4 * result(2)), result(3) = (c23 + c32) / (4 * result(2));
    else if (c33 >= c11 + c22)
        result(3) = 0.5 * sqrt(1 - c11 - c22 + c33), result(0) = (c21 - c12) / (4 * result(3)), result(1) = (c13 + c31) / (4 * result(3)), result(2) = (c23 + c32) / (4 * result(3));
    else
        result(0) = 0.5 * sqrt(1 + c11 + c22 + c33), result(1) = (c32 - c23) / (4 * result(0)), result(2) = (c13 + c31) / (4 * result(0)), result(3) = (c21 + c12) / (4 * result(0));

    return result;
}

// 方向余弦阵 --> 等效旋转矢量
Vector3d Direct_cosine_matrix::DCM2ERV()
{
    Quaternion_vector qv(this->DCM2QV());
    return qv.QV2ERV();
}

void Direct_cosine_matrix::show()
{
    cout << value << endl;
}

// ==========================================Direct cosine matrix End ============================================

// ==========================================Quaternion Start==========================================

Quaternion_vector::Quaternion_vector(Vector4d input)
{
    for (int i = 0; i < 4; i++)
        value(i) = input(i);
}

void Quaternion_vector::show()
{
    cout << value << endl;
}

void Quaternion_vector::operator=(Quaternion_vector& input)
{
    this->value = input.value;
}
//重载四元数与四元数相乘
Quaternion_vector Quaternion_vector::operator*(Quaternion_vector& input)
{
    qv_temp.initialize();
    Vector4d q1 = this->value, q2 = input.value;
    qv_temp.value(0) = q1(0) * q2(0) - q1(1) * q2(1) - q1(2) * q2(2) - q1(3) * q2(3);
    qv_temp.value(1) = q1(0) * q2(1) + q1(1) * q2(0) + q1(2) * q2(3) - q1(3) * q2(2);
    qv_temp.value(2) = q1(0) * q2(2) + q1(2) * q2(0) + q1(3) * q2(1) - q1(1) * q2(3);
    qv_temp.value(3) = q1(0) * q2(3) + q1(3) * q2(0) + q1(1) * q2(2) - q1(2) * q2(1);
    return qv_temp;
}

void Quaternion_vector::operator<<(Vector4d& vector4)
{
    if (vector4.size() != 4) { cerr << "The Vector4d for Quaternion_vector is wrong." << endl, exit(0); }
    for (int i = 0; i < 4; i++)
        value(i) = vector4(i);
}

// 四元数 --> 欧拉角
Vector3d Quaternion_vector::QV2EA()
{
    Vector3d result = Eigen::Vector3d::Zero();
    double q0 = value(0), q1 = value(1), q2 = value(2), q3 = value(3);
    result(1) = asin(2 * (q2 * q3 + q0 * q1));
    if (abs(2 * (q2 * q3 + q0 * q1)) <= 0.999999)
        result(2) = -atan2(2 * (q1 * q3 - q0 * q2), (q0 * q0 - q1 * q1 - q2 * q2 + q3 * q3)), result(0) = -atan2(2 * (q1 * q2 - q0 * q3), (q0 * q0 - q1 * q1 + q2 * q2 - q3 * q3));
    else
        result(2) = atan2(2 * (q1 * q3 + q0 * q2), (q0 * q0 + q1 * q1 - q2 * q2 - q3 * q3)), result(0) = 0;
    return result;
}

// 四元数 --> 方向余弦阵
Matrix3d Quaternion_vector::QV2DCM()
{
    Matrix3d result = Eigen::Matrix3d::Zero();
    result(0, 0) = value(0) * value(0) + value(1) * value(1) - value(2) * value(2) - value(3) * value(3);
    result(0, 1) = 2 * (value(1) * value(2) - value(0) * value(3));
    result(0, 2) = 2 * (value(1) * value(3) + value(0) * value(2));
    result(1, 0) = 2 * (value(1) * value(2) + value(0) * value(3));
    result(1, 1) = value(0) * value(0) - value(1) * value(1) + value(2) * value(2) - value(3) * value(3);
    result(1, 2) = 2 * (value(2) * value(3) - value(0) * value(1));
    result(2, 0) = 2 * (value(1) * value(3) - value(0) * value(2));
    result(2, 1) = 2 * (value(2) * value(3) + value(0) * value(1));
    result(2, 2) = value(0) * value(0) - value(1) * value(1) - value(2) * value(2) + value(3) * value(3);
    return result;
}

// 四元数 --> 等效旋转矢量
Vector3d Quaternion_vector::QV2ERV()
{
    Vector3d result = Eigen::Vector3d::Zero();
    if (value(0) < 0)
        value = -value;
    double hnorm = acos(value(0));	//等效旋转矢量模值的一半
    double b = 0;
    if (hnorm > 1e-20)
        b = 2 * hnorm / sin(hnorm);
    else
        b = 2;
    result(0) = b * value(1), result(1) = b * value(2), result(2) = b * value(3);
    return result;
}
// ==========================================Quaternion End ============================================

// ==========================================Equivalent rotation vector Start==========================================
Equivalent_rotation_vector::Equivalent_rotation_vector(Vector3d input)
{
    value = input;
}

void Equivalent_rotation_vector::show()
{
    cout << value << endl;
}

void Equivalent_rotation_vector::operator<<(Vector3d& vector3)
{
    value = vector3;
}

void Equivalent_rotation_vector::operator=(Equivalent_rotation_vector& input)
{
    this->value = input.value;
}
//等效旋转矢量 --> 四元数
Vector4d Equivalent_rotation_vector::ERV2QV()
{
    Vector4d result = Eigen::Vector4d::Zero();
    double norm = value.transpose() * value;
    double temp = 0;
    if (norm < 1.e-8)
    {
        result(0) = 1 - norm * (1.0 / 8 - norm / 384);
        temp = 0.5 - norm * (1.0 / 48 - norm / 3840);
    }
    else
    {
        norm = sqrt(norm);
        result(0) = cos(norm / 2);
        temp = sin(norm / 2) / norm;
    }
    result(1) = temp * value(0);
    result(2) = temp * value(1);
    result(3) = temp * value(2);
    return result;
}

//等效旋转矢量 -->方向余弦阵
Matrix3d Equivalent_rotation_vector::ERV2DCM()
{
    Quaternion_vector qv(this->ERV2QV());
    return qv.QV2DCM();
}

//等效旋转矢量 --> 欧拉角
Vector3d Equivalent_rotation_vector::ERV2EA()
{
    Quaternion_vector qv(this->ERV2QV());
    return qv.QV2EA();
}

// ==========================================Equivalent rotation vector End ===========================================
