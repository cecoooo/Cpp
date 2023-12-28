#pragma once
#include <string>
#include <vector>
#include "UserCount.h"
#include <ostream>
using std::string;
using std::vector;
using std::ostream;


class User:UserCount
{
private:
	int id;
	string name = "ab";
	int age = 14;
	string phone = "0000000000";
	vector<int> carrierIds;
public:
	User();
	User(string n, int a, string ph);
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
	string toString();
	friend ostream& operator<<(ostream& os, const User& dt);
};

