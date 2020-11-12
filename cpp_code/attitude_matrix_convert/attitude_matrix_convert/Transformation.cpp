#include"Transformation.h"


Vector geodeticToGeocentric::operator()(double Lamda, double L, double H)
{
	Vector v;
	double N = a / sqrt(1 - pow(e, 2.0)*pow(sin(L), 2.0));
	v.push_back((N + H)*cos(L)*cos(Lamda));
	v.push_back((N + H)*cos(L)*sin(Lamda));
	v.push_back((N*(1 - pow(e, 2.0)) + H)*sin(L));
	return v;
}


Vector geocentricToGeodetic::operator()(double X, double Y, double Z)
{
	Vector v;
	double Lamda = atan2(Y, X);
	v.push_back(Lamda);

	double tanL0 = 0.0;
	double tanL=0.0;
	double L0=0.0;
	double XY = sqrt(pow(X, 2.0) + pow(Y, 2.0));
	do
	{
		tanL0 = tanL;
		tanL = ((Z + (a*pow(e, 2.0)*tanL0) / sqrt(1 + ((1 - pow(e, 2.0))*pow(tanL0, 2.0)))) / XY);
		
	} while (fabs(tanL0 - tanL) >= 1e-6);
	double L = atan(tanL);
	v.push_back(L);
	v.push_back(XY / cos(L) - a / sqrt(1 - pow(e, 2.0)*pow(sin(L), 2.0)));

	return v;
}

Vector Geocentric::getCoordinate()
{
	Vector v;
	v.push_back(X);
	v.push_back(Y);
	v.push_back(Z);
	return v;
}

Vector Geodetic::getCoordinate()
{
	Vector v;
	v.push_back(getAngle(Lamda));
	v.push_back(getAngle(L));
	v.push_back(H);
	return v;
}

double getArc(double angle)
{
	return angle * pi / 180.0;
}

double getAngle(double arc)
{
	return arc * 180.0 / pi;
}

double getE(double a, double b)
{
	return sqrt(pow(a, 2.0) - pow(b, 2.0)) / a;
}