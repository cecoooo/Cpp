#include "RentACar.h"

RentACar::RentACar(string m, int y, string rn, double sph) : Car(m ,y ,rn)
{
	this->rentSumPerHour = sph;
}

RentACar::~RentACar()
{

}

double RentACar::getrentSumPerHour() 
{
	return this->rentSumPerHour;
}

void RentACar::setrentSumPerHour(double sph)
{
	this->rentSumPerHour = sph;
}

string RentACar::toString() 
{
	return "Make: " + this->getMake() + '\n' +
		"Year: " + std::to_string(this->getYear()) + '\n' +
		"Registration number: " + this->getRegistrationNumber() + '\n' +
		"Sum per hour for rent: " + std::to_string(this->getrentSumPerHour());
}