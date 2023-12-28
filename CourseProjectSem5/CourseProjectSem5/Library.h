#pragma once
#include <vector>
#include "Carrier.h"
using std::vector;

class Library
{
private:
	static vector<Carrier> carriers;
public:
	static vector<Carrier> getCarriers();
	static void addCarrier(Carrier c);
	static vector<Carrier> getFreeCarriers();
};

