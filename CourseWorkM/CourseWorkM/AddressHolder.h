#pragma once
#include "Person.h"

class AddressHolder: public Person
{
private: 
	static const int MaxLength = 5;
	int currentLenght;
	char* adr[MaxLength];
public:
	AddressHolder();
	~AddressHolder();
	void addAddress(char* address, int len);
};

