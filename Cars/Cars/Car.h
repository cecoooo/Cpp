#pragma once
#include <string>
#include "MPS.h"
using std::string;

class Car: public MPS
{
private:
	string registrationNumber;
public:
	Car(string m, int y, string rn);
	~Car();
	string getRegistrationNumber();
	void setRegistrationNumber(string rn);
};

