#include "Celsius.h"

Celsius::Celsius() {};

Celsius::Celsius(double t)
{
	this->tempCelsuis = t;
}

Celsius::~Celsius() {}

double Celsius::getTempCelsius() 
{
	return this->tempCelsuis;
}

void Celsius::setTempCelsius(double t) 
{
	this->tempCelsuis = t;
}

double Celsius::ConvertToFahrenheit() 
{
	return (9.0 / 5.0) * this->tempCelsuis + 32;
}