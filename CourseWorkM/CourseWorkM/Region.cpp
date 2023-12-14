#include "Region.h"

Region::Region() 
{
    this->area = "No area selected.";
}

Region::Region(string area) 
{
    this->area = area;
}

Region::~Region() {}

string Region::getArea()
{
	return this->area;
}

void Region::setArea(string area) 
{
	this->area = area;
}