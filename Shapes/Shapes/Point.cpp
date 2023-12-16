#include "Point.h"

Point::Point() {}

Point::Point(int x, int y, char n) 
{
	this->x = x;
	this->y = y;
	this->name = n;
};

Point::~Point() {}

int Point::getX() 
{
	return this->x;
}

int Point::getY()
{
	return this->y;
}

char Point::getName() 
{
	return this->name;
}