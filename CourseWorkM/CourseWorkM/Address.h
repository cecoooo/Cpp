#pragma once
#include "Region.h"

class Address: public Region
{
private:
	string country;
	string town;
	string street;
	int number;
public:
	Address();
	Address(string cnt, string twn, string str, int num);
    Address(string area, string cnt, string twn, string str, int num);
	~Address();
	string getCountry();
	string getTown();
	string getStreet();
	int getNumber();
	void setCountry(string country);
	void setTown(string town);
	void setStreet(string street);
	void setNumber(int number);
    string toString();
    string ToString();
    friend std::ostream& operator<<(std::ostream& os, const Address& address);
};

