#include "Validation.h"
#include "UserCount.h"
#include "ErrMessages.h"
#include "Library.h"
#include <vector>
#include "CarrierCount.h"


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

int Validation::validateCarrierType(string type) 
{
	if (stringLengthWithoutWhiteSpaces(type) < 2)
		return 171;
	return 0;
}

int Validation::validateCarrierAuthor(string author)
{
	if (stringLengthWithoutWhiteSpaces(author) < 2)
		return 172;
	return 0;
}

int Validation::validateCarrierTitle(string title)
{
	if (stringLengthWithoutWhiteSpaces(title) < 2)
		return 173;
	return 0;
}

int Validation::validateCarrierYearOfPublish(int year)
{
	if (year < 0 || year > 2024)
		return 174;
	return 0;
}

int Validation::validateUserId(int id) 
{
	if (id < 0 || id > UserCount::getUserCount())
		return 175;
	return 0;
}

int Validation::validateCarrierId(int id)
{
	if (id < 0 || id > CarrierCount::getCarrierCount())
		return 176;
	return 0;
}

int Validation::validationIdsForBorrowingCarriersByUsers(int userId, int carrierId) 
{
	int codeCarrier = validateCarrierId(carrierId);
	int codeUser = validateUserId(userId);
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
	vector<CarrierDTO> carrIds = Library::getFreeCarriers();
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