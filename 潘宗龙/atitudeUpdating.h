#ifndef _ATITUDEUPDATING_H_
#define _ATITUDEUPDATING_H_
/*
DCM0����ʼ��̬������������
step�������ǲ����ļ��
T����������
w1��w2��w3��һ�����������ڵĽ�����
lamda,L,h�����ȣ�γ�ȴ�ظ�
*/
#include"atitude.h"
#include"Transformation.h"
double getRN(double L);
double getRM(double L);
EquivalentRotationVector getPhin(Vector3d v, double lamda, double L, double h, double T);

template<typename V>
void getdTheta(double step, double T, V w1, V w2, V w3, Vector3d& dTheta1, Vector3d& dTheta2)//��ý�����
{
	int t = T / step;
	int i = 0;
	for (i = 0; i < t / 2; i++)
	{
		dTheta1[0]+ = w1[i] * step;
		dTheta1[1] += w2[i] * step;
		dTheta1[2]+ = w3[i] * step;
	}
	for (int j = i; j < t; j++)
	{
		dTheta2[0]+ = w1[j] * step;
		dTheta2[1] += w2[j] * step;
		dTheta2[2]+ = w3[j] * step;
	}
}

template<typename V>
DirectCosineMatrix atitudeUpdating(DirectCosineMatrix DCM0, V w1, V w2, V w3, EquivalentRotationVector Phin, double step, double T)
{
	Matrix3d I = MatrixXd::Identity(3, 3);

	//���Cb(m)b(m-1)
	Vector3d dTheta1 = Eigen::Vector3d::Zero();
	Vector3d dTheta2 = Eigen::Vector3d::Zero();
	getdTheta(step, T, w1, w2, w3, dTheta1, dTheta2);
	EquivalentRotationVector Phib(dTheta1 + dTheta2 + 2 / 3 * dTheta1.cross(dTheta2));
	DirectCosineMatrix cb = Phib.ervToDCM();
	Matrix3d Cb;
	cb.getDCM(Cb);

	//���Cn(m-1)n(m)
	DirectCosineMatrix cn = Phin.ervToDCM();
	Matrix3d Cn;
	cn.getDCM(Cn);
	Cn = Cn.transpose();

	//���Cb(m)n(m)
	Matrix3d dcm0;
	DCM0.getDCM(dcm0);
	DirectCosineMatrix DCM(Cn*dcm0*Cb);
	return DCM;
}



#endif