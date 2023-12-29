#include "CarrierCount.h"
#include <sstream>
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::string;

int convertToNumberCarrierId(string s)
{
	int i = 0;
	for (char c : s)
		if (c >= '0' && c <= '9')
			i = i * 10 + (c - '0');
	return i;
}

int CarrierCount::getLatestCarrierId()
{
	ifstream carrierFileRead;
	carrierFileRead.open("carriersIds.txt");
	string line;
	int res=0;
	while (getline(carrierFileRead, line)) 
		res = convertToNumberCarrierId(line);
	return res;
}

int CarrierCount::carrierCount = getLatestCarrierId();

int CarrierCount::getCarrierCount() 
{
	return carrierCount;
}

void CarrierCount::increaseCarrierCount()
{
	carrierCount++;
	ofstream carrierFileWrite;
	carrierFileWrite.open("carriersIds.txt");
	carrierFileWrite << carrierCount;
	carrierFileWrite.close();
}