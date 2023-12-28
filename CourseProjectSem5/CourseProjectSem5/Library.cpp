#include "Library.h"
#include <sstream>
using std::stringstream;

const string Library::userFilePath = "user.txt";
const string Library::carrierFilePath = "carrier.txt";
ofstream Library::userFileWrite(userFilePath, std::ios::app);
ofstream Library::carrierFileWrite(carrierFilePath, std::ios::app);
ifstream Library::userFileRead(userFilePath);
ifstream Library::carrierFileRead(carrierFilePath);

//vector<Carrier> Library::getCarriers()
//{
//	vector<Carrier> carriers;
//	string line;
//	while (getline(carrierFileRead, line)) {
//		Carrier c;
//		stringstream ss(line);
//		string world;
//		while (getline(ss, world, '/'))
//		{
//			c.id
//		}
//		/*os << c.id << '/' << c.type << '/' << c.title << '/' << c.author
//			<< '/' << c.yearOfPublish << '/' << c.userId << '\n';*/
//	}
//
//
//	return carriers;
//}

void Library::addCarrier(Carrier c)
{
	carrierFileWrite << c;
	carrierFileWrite.close();
}

//vector<Carrier> Library::getFreeCarriers()
//{
//	vector<Carrier> res;
//	for (size_t i = 0; i < carriers.size(); i++)
//		if (carriers[i].getState())
//			res.push_back(carriers[i]);
//	return res;
//}