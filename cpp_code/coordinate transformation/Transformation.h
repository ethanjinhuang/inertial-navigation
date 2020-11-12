#ifndef _TRANSFORMATION_H_
#define _TRANSFORMATION_H_
#include<cmath>
#include<vector>
typedef std::vector<double> Vector;
const double pi = acos(-1);


double getArc(double angle);
double getAngle(double arc);
double getE(double a, double b);
//大地坐标系
class Geodetic
{
protected:
	double Lamda;
	double L;
	double H;
public:
	Geodetic(double lamda, double l, double h) :Lamda(lamda), L(l), H(h) {}
	//地心->大地，可自定义算法
	template<typename VST> Geodetic(double X, double Y, double Z, VST&& func);
	Vector getCoordinate();//获得坐标
};

//地心坐标系
class Geocentric
{
protected:
	double X;
	double Y;
	double Z;
public:
	Geocentric(double x, double y, double z) :X(x), Y(y), Z(z) {}
	//大地->地心，可自定义算法
	template<typename VST> Geocentric(double Lamda, double L, double H, VST&& func);
	Vector getCoordinate();//获得坐标
};

template<typename VST>
Geocentric::Geocentric(double Lamda, double L, double H, VST&& func)
{
	Lamda = getArc(Lamda);
	L = getArc(L);
	Vector v = func(Lamda, L, H);
	X = v[0];
	Y = v[1];
	Z = v[2];
}



template<typename VST> 
Geodetic::Geodetic(double X, double Y, double Z, VST&& func)
{
	Vector v = func(X, Y, Z);
	Lamda = v[0];
	L = v[1];
	H = v[2];
}



class geodeticToGeocentric
{
protected:
	double a;
	double b;
	double e;
public:
	geodeticToGeocentric(double A = 6378137, double B = 6356752.3142) :a(A), b(B)
	{
		e = getE(a, b);
	}
	Vector operator()(double Lamda, double L, double H);
};

class geocentricToGeodetic
{
protected:
	double a;
	double b;
	double e;
public:
	geocentricToGeodetic(double A = 6378137, double B = 6356752.3142) :a(A), b(B)
	{
		e = getE(a, b);
	}
	Vector operator()(double X, double Y, double Z);
};



#endif // !_TRANSFORMATION_H_


