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
	static int validateCarrierType(string type);
	static int validateCarrierAuthor(string author);
	static int validateCarrierTitle(string title);
	static int validateCarrierYearOfPublish(int year);
	static int validateUserId(int id);
	static int validateCarrierId(int id);
	static int validationIdsForBorrowingCarriersByUsers(int userId, int carrierId);
};

