#pragma once
#include <string>
#include <iostream>
using std::string;

class Person
{
private:
	string name;
	string egn;
	char* address;
public:
	Person();
	~Person();
	string getName();
	string getEGN();
	char* getAddress();
	void setName(string name);
	void setEGN(string egn);
	void setAddress(char* address, int len);
};

