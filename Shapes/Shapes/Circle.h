#pragma once
#include "Point.h"

class Circle
{
private:
	Point point;
	int radius;
public:
	Circle();
	Circle(Point p, int r);
	~Circle();
	int getRadius();
	void getInfo();

};

