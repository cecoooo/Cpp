#include "Library.h"
#include <sstream>
#include "Validation.h"
#include "ErrMessages.h"
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
	vector<CarrierDTO> carrs = getCarriers();
	for (size_t i = 0; i < carrs.size(); i++)
		if (!carrs[i].getState())
			res.push_back(carrs[i]);
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

void Library::clearUserFile() 
{
	userFileWrite.open(userFilePath);
	userFileWrite.close();
	ofstream userFileWriteCount;
	userFileWriteCount.open("usersIds.txt");
	userFileWriteCount << 0;
	userFileWriteCount.close();
	UserCount::refreshUserCounter();
}

void Library::clearCarrierFile()
{
	carrierFileWrite.open(carrierFilePath);
	carrierFileWrite.close();
	ofstream carrierFileWriteCount;
	carrierFileWriteCount.open("carriersIds.txt");
	carrierFileWriteCount << 0;
	carrierFileWriteCount.close();
	CarrierCount::refreshCarrierCounter();
}

int Library::idValidation(int userId, int carrierId)
{
	int codeCarrier = Validation::validateCarrierId(carrierId);
	int codeUser = Validation::validateUserId(userId);
	bool isValidIds = true;
	if (codeCarrier) {
		ErrMessages::NoCarrierFindWithGivenId();
		isValidIds = false;
	}
	if (codeUser) {
		ErrMessages::NoUserFindWithGivenId();
		isValidIds = false;
	}
	if (!isValidIds)
		return 1;
	vector<CarrierDTO> carrIds = getFreeCarriers();
	bool isFreeCarrier = false;
	for (size_t i = 0; i < carrIds.size(); i++) {
		if (carrIds[i].getId() == carrierId) {
			isFreeCarrier = true;
			break;
		}
	}
	if (!isFreeCarrier) {
		ErrMessages::CarrierNotFree();
		return 1;
	}
	return 0;
}

void Library::borrowCarrierWithUser(int userId, int carrierId)
{
	if (idValidation(userId, carrierId)) return;
	vector<UserDTO> userDTOs = getUsers();
	vector<CarrierDTO> carrierDTOs = getCarriers();
	clearUserFile();
	clearCarrierFile();
	for (size_t i = 0; i < carrierDTOs.size(); i++)
	{
		if (carrierDTOs[i].getId() == carrierId) {
			Carrier c(carrierDTOs[i].getType(), carrierDTOs[i].getAuthor(), carrierDTOs[i].getTitle(),
				carrierDTOs[i].getYearOfPublish(), userId);
			continue;
		}
		Carrier c1(carrierDTOs[i].getType(), carrierDTOs[i].getAuthor(), carrierDTOs[i].getTitle(),
			carrierDTOs[i].getYearOfPublish(), carrierDTOs[i].getState());
	}
	for (size_t i = 0; i < userDTOs.size(); i++)
	{
		if (userDTOs[i].getId() == userId) {
			User u(userDTOs[i].getName(), userDTOs[i].getAge(), userDTOs[i].getPhone(), 
				userDTOs[i].getCarrierIds(), carrierId);
			continue;
		}
		User u1(userDTOs[i].getName(), userDTOs[i].getAge(), userDTOs[i].getPhone(), 
			userDTOs[i].getCarrierIds());
	}
}

