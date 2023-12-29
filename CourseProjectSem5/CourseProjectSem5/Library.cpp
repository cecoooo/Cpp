#include "Library.h"
#include <sstream>
using std::stringstream;

const string Library::userFilePath = "user.txt";
const string Library::carrierFilePath = "carrier.txt";
ofstream Library::userFileWrite;
ofstream Library::carrierFileWrite;
ifstream Library::userFileRead;
ifstream Library::carrierFileRead;

int convertToNumber(string s) 
{
	int i = 0;
	for (char c : s) 
		if (c >= '0' && c <= '9') 
			i = i * 10 + (c - '0');
	return i;
}

vector<CarrierDTO> Library::getCarriers()
{
	carrierFileRead.open(carrierFilePath);
	vector<CarrierDTO> carriers;
	string line;
	while (getline(carrierFileRead, line)) {
		stringstream ss(line);
		string word;
		string arr[6];
		int j = 0;
		while (getline(ss, word, '/'))
		{
			arr[j] = word;
			j++;
		}
		CarrierDTO c(convertToNumber(arr[0]), arr[1], arr[2], arr[3], 
			convertToNumber(arr[4]), convertToNumber(arr[5]));
		carriers.push_back(c);
	}
	carrierFileRead.close();
	return carriers;
}

void Library::addCarrier(Carrier c)
{
	carrierFileWrite.open(carrierFilePath, std::ios::app);
	carrierFileWrite << c;
	carrierFileWrite.close();
}

vector<CarrierDTO> Library::getFreeCarriers()
{
	vector<CarrierDTO> res;
	for (size_t i = 0; i < getCarriers().size(); i++)
		if (getCarriers()[i].getState())
			res.push_back(getCarriers()[i]);
	return res;
}

vector<UserDTO> Library::getUsers() 
{
	userFileRead.open(userFilePath);
	vector<UserDTO> users;
	string line;
	while (getline(userFileRead, line)) {
		stringstream ss(line);
		string word;
		string arr[4];
		int j = 0;
		UserDTO u;
		while (getline(ss, word, '/'))
		{
			if (j < 4) 
			{
				arr[j] = word;
				j++;
			}
			else 
			{
				u.borrowCarrier(convertToNumber(word));
			}
		}
		u.setId(convertToNumber(arr[0]));
		u.setName(arr[1]);
		u.setAge(convertToNumber(arr[2]));
		u.setPhone(arr[3]);
		users.push_back(u);
	}
	userFileRead.close();
	return users;
}

void Library::addUser(User u) 
{
	userFileWrite.open(userFilePath, std::ios::app);
	userFileWrite << u;
	userFileWrite.close();
}