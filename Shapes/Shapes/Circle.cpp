#include "Circle.h"
#include <iostream>

Circle::Circle() {}

Circle::Circle(Point p, int r) 
{
	this->point = p;
	this->radius = r;
}

Circle::~Circle() {}

int Circle::getRadius() 
{
	return this->radius;
}

void Circle::getInfo() 
{
	std::cout << "X: " + std::to_string(this->point.getX()) + "\n" +
		"Y: " + std::to_string(this->point.getY()) + "\n" +
		"Radius: " + std::to_string(this->radius) + "\n" +
		"Point Name: " + this->point.getName() << std::endl;
}