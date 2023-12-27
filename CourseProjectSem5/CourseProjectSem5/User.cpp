#include "User.h"


//User();
//User(int i, string n, int a, string ph);
//~User();
//int getId();
//string getName();
//int getAge();
//string getPhone();
//vector<int> getCarrierIds();
//void setName(string n);
//void setAge(int a);
//void setPhone(string p);
//void borrowCarrier(int c);


User::User() 
{
	UserCount::increaseUserCount();
	this->id = UserCount::getUserCount();
}

User::User(int i, string n, int a, string ph) 
{
	UserCount::increaseUserCount();
	this->id = UserCount::getUserCount();
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
	if (n.size() > 50 || n.size() < 2) 
	{
		
	}
}