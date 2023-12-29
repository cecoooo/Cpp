#include "User.h"
#include "ErrMessages.h"
#include "Validation.h"
#include <iostream>
#include "Library.h"
using std::cin;
using std::cout;
using std::endl;


User::User() 
{
	UserCount::increaseUserCount();
	this->id = UserCount::getUserCount();
	Library::addUser(*this);
}

User::User(string n, int a, string ph) 
{
	setName(n);
	setAge(a);
	setPhone(ph);
	UserCount::increaseUserCount();
	this->id = UserCount::getUserCount();
	Library::addUser(*this);
}

User::~User() {}

int User::getId() 
{
	return this->id;
}

string User::getName() 
{
	return this->name;
}

int User::getAge()
{
	return this->age;
}

string User::getPhone()
{
	return this->phone;
}

vector<int> User::getCarrierIds() 
{
	return this->carrierIds;
}

void User::setName(string n) 
{
	int code = Validation::validateUserName(n);
	while (code)
	{
		if(code == 161)
			ErrMessages::UserNameTooLongError();
		if (code == 162)
			ErrMessages::UserNameTooShortError();
		else
			ErrMessages::UnknownException();
		cout << "Try Again: " << endl;
		cin >> n;
		code = Validation::validateUserName(n);
	}
	this->name = n;
}

void User::setAge(int a) 
{
	int code = Validation::validateUserAge(a);
	while (code)
	{
		if (code == 163)
			ErrMessages::InvalidUserAge();
		else
			ErrMessages::UnknownException();
		cout << "Try Again: " << endl;
		cin >> a;
		code = Validation::validateUserAge(a);
	}
	this->age = a;
}

void User::setPhone(string ph) 
{
	int code = Validation::validateUserPhone(ph);
	while (code)
	{
		if (code == 164)
			ErrMessages::UserPhoneNotProperLenght();
		else if (code == 165)
			ErrMessages::UserPhoneContainInvalidSymbols();
		else
			ErrMessages::UnknownException();
		cout << "Try Again: " << endl;
		cin >> ph;
		code = Validation::validateUserPhone(ph);
	}
	this->phone = ph;
}

void User::borrowCarrier(int id) 
{
	this->carrierIds.push_back(id);
}

string User::toString() 
{
	return "User ID: " + std::to_string(this->id) + '\n' +
		"Name: " + this->name + '\n' +
		"Age: " + std::to_string(this->age) + '\n' +
		"Phone: " + this->phone + '\n';
}

ostream& operator<<(ostream& os, const User& u)
{
	os << u.id << '/' << u.name << '/' << u.age << '/' << u.phone;
	for (size_t i = 0; i < u.carrierIds.size(); i++)
	{
		os << '/' << u.carrierIds[i];
	}
	os << '\n';
	return os;
}