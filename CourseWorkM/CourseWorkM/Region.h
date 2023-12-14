#pragma once
#include <iostream>
using std::string;

class Region
{
private:
	string area;
public:
    Region();
    Region(string area);
	~Region();
	string getArea();
	void setArea(string area);
};

