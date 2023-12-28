#pragma once
#include <string>
using std::string;

class Validation
{
private:
	static int stringLengthWithoutWhiteSpaces(string s);
	static bool checkPhoneForInvalidSymbols(string ph);
public:
	static int validateUserName(string name);
	static int validateUserAge(int age);
	static int validateUserPhone(string phone);
};

