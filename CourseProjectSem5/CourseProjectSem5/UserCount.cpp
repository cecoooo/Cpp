#include "UserCount.h"
#include <sstream>
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::string;

int convertToNumberUserId(string s)
{
	int i = 0;
	for (char c : s)
		if (c >= '0' && c <= '9')
			i = i * 10 + (c - '0');
	return i;
}

int UserCount::getLatestUserId() 
{
	ifstream userFileRead;
	userFileRead.open("usersIds.txt");
	string line;
	int res = 0;
	while (getline(userFileRead, line))
		res = convertToNumberUserId(line);
	return res;
}

int UserCount::userCount = getLatestUserId();

int UserCount::getUserCount()
{
	return userCount;
}
void UserCount::increaseUserCount()
{
	userCount++;
	ofstream userFileWrite;
	userFileWrite.open("usersIds.txt");
	userFileWrite << userCount;
	userFileWrite.close();
}

void UserCount::refreshUserCounter() 
{
	userCount = getLatestUserId();
}