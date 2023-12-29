#include "UserDTO.h"

UserDTO::UserDTO(){}

UserDTO::UserDTO(int i, string n, int a, string ph)
{
	setId(i);
	setName(n);
	setAge(a);
	setPhone(ph);
}

UserDTO::~UserDTO() {}

int UserDTO::getId()
{
	return this->id;
}

string UserDTO::getName()
{
	return this->name;
}

int UserDTO::getAge()
{
	return this->age;
}

string UserDTO::getPhone()
{
	return this->phone;
}

vector<int> UserDTO::getCarrierIds()
{
	return this->carrierIds;
}

void UserDTO::setId(int i) 
{
	this->id = i;
}

void UserDTO::setName(string n)
{
	this->name = n;
}

void UserDTO::setAge(int a)
{
	this->age = a;
}

void UserDTO::setPhone(string ph)
{
	this->phone = ph;
}

void UserDTO::borrowCarrier(int id)
{
	this->carrierIds.push_back(id);
}

string UserDTO::toString()
{
	return "User ID: " + std::to_string(this->id) + '\n' +
		"Name: " + this->name + '\n' +
		"Age: " + std::to_string(this->age) + '\n' +
		"Phone: " + this->phone + '\n';
}