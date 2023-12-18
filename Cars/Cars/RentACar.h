#pragma once
#include "Car.h"

class RentACar: public Car
{
private:
	double rentSumPerHour;
public:
	RentACar(string m, int y, string rn, double sph);
	~RentACar();
	double getrentSumPerHour();
	void setrentSumPerHour(double sph);
	string toString();
};

