#pragma once
#include "Temperature.h"

class Celsius: public Temperature
{
private:
	double tempCelsuis;
public:
	Celsius();
	Celsius(double t);
	~Celsius();
	double getTempCelsius();
	void setTempCelsius(double t);
	double ConvertToFahrenheit() override;
};

