#include"Transformation.h"
#include<iostream>
using namespace std;


int main()
{
	//大地->地心
	geodeticToGeocentric func0;
	Geocentric c(20.22, 30.33, 100.211, func0);
	stdVectord v0(c.getCoordinate());
	cout << "(X,Y,Z)" << endl;
	for (auto i : v0)
	{
		cout << i << endl;
	}
	cout << endl;
	//地心->大地
	cout << "(lamda,L,h)" << endl;
	geocentricToGeodetic func1;
	Geodetic g(c.getCoordinate(), func1);
	stdVectord v(g.getCoordinate());
	for (auto i:v)
	{
		cout << i << endl;
	}

	//大地->地心
	Geocentric c0(g.getCoordinate(), func0);
	stdVectord v2(c0.getCoordinate());
	cout << "(X,Y,Z)" << endl;
	for (auto i : v2)
	{
		cout << i << endl;
	}

	system("pause");
	return 0;
}