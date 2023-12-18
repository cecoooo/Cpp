#include "Car.h"

Car::Car(string m, int y, string rn) : MPS(m, y)
{
	this->registrationNumber = rn;
}

Car::~Car()
{

}

string Car::getRegistrationNumber() 
{
	return this->registrationNumber;
}

void Car::setRegistrationNumber(string rn)
{
	this->registrationNumber = rn;
}