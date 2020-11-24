#include "atitudeUpdating.h"

double getRN(double L)
{
	return Re / sqrt((1 - pow(e, 2.0)*pow(sin(L), 2.0)));
}

double getRM(double L)
{
	return Re * (1 - pow(e, 2.0)) / sqrt(pow((1 - pow(e, 2.0)*pow(sin(L), 2.0)), 3.0));
}

EquivalentRotationVector getPhin(Vector3d v, double lamda, double L, double h, double T)//4.1.3��4.1.4
{
	Matrix3d Cge;
	double vn = v[1];
	double ve = v[0];
	Cge << (-sin(lamda)), (-sin(L)*cos(lamda)), cos(L)*cos(lamda), cos(lamda), (-sin(L)*sin(lamda))
		, cos(L)*sin(lamda), 0, cos(L), sin(L);
	Vector3d Wiee;
	Wiee << 0, 0, Wie;
	Vector3d Wien = Cge.transpose()*Wiee;
	Vector3d Wenn;
	Wenn << (-vn / (getRM(L) + h)), ve / (getRN(L) + h), ve / (getRN(L) + h)*tan(L);
	Vector3d Winn = Wien + Wenn;
	return EquivalentRotationVector(T * Winn);
}
