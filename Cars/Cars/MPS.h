#pragma once
#include <string>
using std::string;

class MPS
{
private:
	string make;
	int year;
public:
	MPS(string m, int y);
	~MPS();
	string getMake();
	int getYear();
	void setMake(string m);
	void setYear(int y);
};

