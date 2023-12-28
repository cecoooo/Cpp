#pragma once
#include <vector>
#include "Carrier.h"
#include <fstream>
using std::vector;
using std::ofstream;
using std::ifstream;

class Library
{
private:
	static const string userFilePath;
	static const string carrierFilePath;
	static ofstream userFileWrite;
	static ofstream carrierFileWrite;
	static ifstream userFileRead;
	static ifstream carrierFileRead;
public:
	static vector<Carrier> getCarriers();
	static void addCarrier(Carrier c);
	static vector<Carrier> getFreeCarriers();
};

