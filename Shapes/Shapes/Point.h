#pragma once
#include <string>
using std::string;

class Point
{
private:
	int x;
	int y;
	char name;
public:
	Point();
	Point(int x, int y, char n);
	~Point();
	int getX();
	int getY();
	char getName();
};

