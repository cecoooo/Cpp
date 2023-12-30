#pragma once
#include <string>
using std::string;

class ErrMessages
{
public:
	static void UnknownException();
	static void UserNameTooLongError();
	static void UserNameTooShortError();
	static void InvalidUserAge();
	static void UserPhoneContainInvalidSymbols();
	static void UserPhoneNotProperLenght();
	static void CarrierInvalidTypeException();
	static void CarrierInvalidAuthorException();
	static void CarrierInvalidTitleException();
	static void CarrierInvalidYearException();
	static void NoUserFindWithGivenId();
	static void NoCarrierFindWithGivenId();
	static void CarrierNotFree();
};

