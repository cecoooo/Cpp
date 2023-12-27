#pragma once
#include <string>
#include <vector>
#include "UserCount.h"
using std::string;
using std::vector;


class User:UserCount
{
private:
	int id;
	string name;
	int age=0;
	string phone;
	vector<int> carrierIds;
public:
	User();
	User(int i, string n, int a, string ph);
	~User();
	int getId();
	string getName();
	int getAge();
	string getPhone();
	vector<int> getCarrierIds();
	void setName(string n);
	void setAge(int a);
	void setPhone(string p);
	void borrowCarrier(int c);
};

