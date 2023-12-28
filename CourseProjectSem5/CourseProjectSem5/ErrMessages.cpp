#include "ErrMessages.h"
#include <iostream> 
using std::cout;
using std::endl;

void ErrMessages::UnknownException() 
{
	cout << "UNKNOWN EXCEPTION." << endl;
}

void ErrMessages::UserNameTooLongError() 
{
	cout << "User's name is over 50 symbols.\nPlease Enter name between 2 and 50 symbols including." << endl;
}

void ErrMessages::UserNameTooShortError()
{
	cout << "User's name is lower than 2 symbols lenght.\nPlease Enter name between 2 and 50 symbols including." << endl;
}

void ErrMessages::InvalidUserAge()
{
	cout << "Invalid user's age.\nAge must be between 14 and 120 years." << endl;
}

void ErrMessages::UserPhoneNotProperLenght()
{
	cout << "Invalid user's phone.\nPhone must be exactly 10 symbols long."<< endl;
}

void ErrMessages::UserPhoneContainInvalidSymbols()
{
	cout << "Invalid user's phone.\nPhone must contains only numbers from 0 to 9." << endl;
}