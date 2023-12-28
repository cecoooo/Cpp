#include "Validation.h"
#include "ErrMessages.h"


int Validation::stringLengthWithoutWhiteSpaces(string s) 
{
	int count = 0;
	for (size_t i = 0; i < s.size(); i++)
		if (s[i] != ' ')
			count++;
	return count;
}

bool Validation::checkPhoneForInvalidSymbols(string ph) 
{
	for (size_t i = 0; i < ph.size(); i++)
		if (!isdigit(ph[i]))
			return false;
	return true;
}

int Validation::validateUserName(string name) 
{
	int nameWithoutWhiteSpaces = stringLengthWithoutWhiteSpaces(name);
	if (nameWithoutWhiteSpaces > 50)
		return 161;
	else if (nameWithoutWhiteSpaces < 2)
		return 162;
	return 0;
}

int Validation::validateUserAge(int age) 
{
	if (age < 14 || age > 120) 
		return 163;
	return 0;
}

int Validation::validateUserPhone(string phone)
{
	if (phone.size() != 10)
		return 164;
	else if (!checkPhoneForInvalidSymbols(phone))
		return 165;
	return 0;
}