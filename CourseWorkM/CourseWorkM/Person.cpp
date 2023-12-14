#include "Person.h"
#include <ostream>
using std::ostream;
using std::strcpy;


Person::Person() {}

Person::Person(string nm, string egn, Address adr) 
{
    this->name = nm;
    this->egn = egn;
    address = adr;
}

Person::~Person() {}

string Person::getName() 
{
	return this->name;
}

string Person::getEGN() 
{
	return this->egn;
}

Address Person::getAddress() 
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

void Person::setAddress(Address adr)
{
	this->address = adr;
}

std::ostream& operator<<(std::ostream& os, const Person& person) {
	os << "Name: " << person.name << std::endl;
	os << "EGN: " << person.egn << std::endl;
	return os;
}

string Person::toString() 
{
	return "PERSON DATA\nName: " + this->name + "\n"
		+ "EGN: " + this->egn + "\n"
		+ "Address: " + this->address.toString();
}