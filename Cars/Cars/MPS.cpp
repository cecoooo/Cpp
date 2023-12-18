#include "MPS.h"

MPS::MPS(string m, int y) 
{
	this->make = m;
	this->year = y;
}

MPS::~MPS()
{
	
}

string MPS::getMake() 
{
	return this->make;
}

int MPS::getYear()
{
	return this->year;
}

void MPS::setMake(string m)
{
	this->make = m;
}

void MPS::setYear(int y)
{
	this->year = y;
}
