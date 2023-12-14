#pragma once
#include <string>
#include <iostream>
#include <ostream>
#include "Address.h"
using std::ostream;
using std::string;
using std::endl;

class Person
{
private:
	string name;
	string egn;
	Address address;
public:
    Person();
    Person(string nm, string egn, Address adr);
	~Person();
	string getName();
	string getEGN();
	Address getAddress();
	void setName(string name);
	void setEGN(string egn);
	void setAddress(Address adr);
	string toString();
	friend std::ostream& operator<<(std::ostream& os, const Person& person);
};

