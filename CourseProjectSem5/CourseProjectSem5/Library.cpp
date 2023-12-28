#include "Library.h"

vector<Carrier> Library::carriers;

vector<Carrier> Library::getCarriers()
{
	return carriers;
}

void Library::addCarrier(Carrier c)
{
	carriers.push_back(c);
}

vector<Carrier> Library::getFreeCarriers()
{
	vector<Carrier> res;
	for (size_t i = 0; i < carriers.size(); i++)
		if (carriers[i].getState())
			res.push_back(carriers[i]);
	return res;
}