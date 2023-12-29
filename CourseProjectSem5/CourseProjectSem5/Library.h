#pragma once
#include <vector>
#include "Carrier.h"
#include <fstream>
#include "UserDTO.h"
#include "User.h"
#include "CarrierDTO.h"
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
	static vector<UserDTO> getUsers();
	static void addUser(User u);
	static vector<CarrierDTO> getCarriers();
	static void addCarrier(Carrier c);
	static vector<CarrierDTO> getFreeCarriers();
};

