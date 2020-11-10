#pragma once
#include<iostream>
#include<Eigen\Dense>
#include<math.h>
using namespace Eigen;
using namespace std;

//类声明
class Euler_angle;
class Direct_cosine_matrix;
class Quaternion;

// 欧拉角
class Euler_angle
{
public:
	Vector3f value = Eigen::Vector3f::Zero();
	Euler_angle() { value = Eigen::Vector3f::Zero(); }
	Euler_angle(float phi, float theta, float gamma);
	Euler_angle(Vector3f input_vector);
	void show();
	Matrix3f EA2DCM();	// 欧拉角-->方向余弦阵

};
// 方向余弦阵
class Direct_cosine_matrix
{
public:
	Matrix3f value = Eigen::Matrix3f::Zero();
	Direct_cosine_matrix() { value = Eigen::Matrix3f::Zero(); }
	Direct_cosine_matrix(Matrix3f input_matrix);
	Vector3f DCM2EA();
	void show();
	
};

// ==========================================Euler Start==========================================

Euler_angle::Euler_angle(float phi, float theta, float gamma)
{
	value[0] = phi; value[1] = theta; value[2] = gamma;
}

Euler_angle::Euler_angle(Vector3f inputvector)
{
	value = inputvector;
}

void Euler_angle::show()
{
	cout << value << endl;
}

Matrix3f Euler_angle::EA2DCM()
{
	Matrix3f result=Eigen::Matrix3f::Zero();
	result(0, 0) = cos(value(0))*cos(value(2)) - sin(value(0))*sin(value(1))*sin(value(2));
	result(0, 1) = -sin(value(0))*cos(value(1));
	result(0, 2) = cos(value(0))*sin(value(2)) + sin(value(0))*sin(value(1))*cos(value(2));
	result(1, 0) = sin(value(0))*cos(value(2)) + cos(value(0))*sin(value(1))*sin(value(2));
	result(1, 1) = cos(value(0))*cos(value(1));
	result(1, 2) = sin(value(0))*sin(value(2)) - cos(value(0))*sin(value(1))*cos(value(2));
	result(2, 0) = -cos(value(1))*sin(value(2));
	result(2, 1) = sin(value(1));
	result(2, 2) = cos(value(1))*cos(value(2));
	return result;
}


// ========================================== Euler End ===========================================

Direct_cosine_matrix::Direct_cosine_matrix(Matrix3f input_matrix)
{
	value = input_matrix;
}

Vector3f Direct_cosine_matrix::DCM2EA()
{
	Vector3f result = Eigen::Vector3f::Zero();
}


void Direct_cosine_matrix::show()
{
	cout << value << endl;
}

