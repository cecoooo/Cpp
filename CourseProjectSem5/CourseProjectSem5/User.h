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
	User(string n, int a, string ph);
	User(string n, int a, string ph, vector<int> ids);
	User(string n, int a, string ph, vector<int> ids, int i);
	~User();
	int getId();
	string getName();
	int getAge();
	string getPhone();
	vector<int> getCarrierIds();
	void setName(string n);
	void setAge(int a);
	void setPhone(string p);
	void setCarrierIds(vector<int> cIds);
	void setCarrierIds(vector<int> ids, int id);
	string toString();
	friend ostream& operator<<(ostream& os, const User& dt);
};

