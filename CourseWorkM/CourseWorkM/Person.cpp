#include "Person.h"
using std::strcpy;

Person::Person() 
{
	
}
Person::~Person() 
{
	if (this->address != NULL) 
	{
		free(this->address);
		this->address = NULL;
	}
}

string Person::getName() 
{
	return this->name;
}

string Person::getEGN() 
{
	return this->egn;
}

char* Person::getAddress() 
{
	return this->address;
}

void Person::setName(string name) 
{
	this->name = name;
}

void Person::setEGN(string egn)
{
	this->egn = egn;
}

void Person::setAddress(char* address, int len)
{
	char* newAdr = (char*)malloc(len);
	strcpy_s(newAdr, len, address);
	this->address = newAdr;
}