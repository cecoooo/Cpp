#include "Carrier.h"
#include <iostream>
#include "Library.h"
#include "ErrMessages.h"
#include "Validation.h"
using std::cin;
using std::cout;
using std::endl;

Carrier::Carrier(string ty, string au, string ti, int y)
{
	setType(ty);
	setAuthor(au);
	setTitle(ti);
	setYearOfPublish(y);
	CarrierCount::increaseCarrierCount();
	this->id = CarrierCount::getCarrierCount();
	Library::addCarrier(*this);
}

Carrier::Carrier(string ty, string au, string ti, int y, int i)
{
	setType(ty);
	setAuthor(au);
	setTitle(ti);
	setYearOfPublish(y);
	this->userId = i;
	CarrierCount::increaseCarrierCount();
	this->id = CarrierCount::getCarrierCount();
	Library::addCarrier(*this);
}

Carrier::~Carrier() {}

int Carrier::getId() 
{
	return this->id;
}

string Carrier::getType()
{
	return this->type;
}

string Carrier::getAuthor()
{
	return this->author;
}

string Carrier::getTitle()
{
	return this->title;
}

int Carrier::getYearOfPublish()
{
	return this->yearOfPublish;
}

int Carrier::getState()
{
	return this->userId;
}

void Carrier::setType(string ty) 
{
	int code = Validation::validateCarrierType(ty);
	while (code)
	{
		if (code == 171)
			ErrMessages::CarrierInvalidTypeException();
		else
			ErrMessages::UnknownException();
		cout << "Try Again: " << endl;
		cin >> ty;
		code = Validation::validateCarrierType(ty);
	}
	this->type = ty;
}

void Carrier::setAuthor(string au) 
{
	int code = Validation::validateCarrierAuthor(au);
	while (code)
	{
		if (code == 172)
			ErrMessages::CarrierInvalidAuthorException();
		else
			ErrMessages::UnknownException();
		cout << "Try Again: " << endl;
		cin >> au;
		code = Validation::validateCarrierAuthor(au);
	}
	this->author = au;
}

void Carrier::setTitle(string ti) 
{
	int code = Validation::validateCarrierTitle(ti);
	while (code)
	{
		if (code == 173)
			ErrMessages::CarrierInvalidTitleException();
		else
			ErrMessages::UnknownException();
		cout << "Try Again: " << endl;
		cin >> ti;
		code = Validation::validateCarrierTitle(ti);
	}
	this->title = ti;
}

void Carrier::setYearOfPublish(int y)
{
	int code = Validation::validateCarrierYearOfPublish(y);
	while (code)
	{
		if (code == 174)
			ErrMessages::CarrierInvalidYearException();
		else
			ErrMessages::UnknownException();
		cout << "Try Again: " << endl;
		cin >> y;
		code = Validation::validateCarrierYearOfPublish(y);
	}
	this->yearOfPublish = y;
}

void Carrier::setState(int id)
{
	int code = Validation::validateUserId(id);
	while (code)
	{
		if (code == 175)
			ErrMessages::NoUserFindWithGivenId();
		else
			ErrMessages::UnknownException();
		cout << "Try Again: " << endl;
		cin >> id;
		code = Validation::validateUserId(id);
	}
	this->userId = id;
}

string Carrier::toString() 
{
	string status;
	if (this->userId == 0)
		status = "Carrier is accessible";
	else
		status = "Carrier is unaccessible";
	return "Carrier ID: " + std::to_string(this->id) + '\n' +
		"Carrier type: " + this->type + '\n' +
		"Author: " + this->author + '\n' +
		"Title: " + this->title + '\n' +
		"Year of publish: " + std::to_string(this->yearOfPublish) + '\n' +
		status + '\n';
}

ostream& operator<<(ostream& os, const Carrier& c)
{
	os << c.id << '/' << c.type << '/' << c.author << '/' << c.title 
		<< '/' << c.yearOfPublish << '/' << c.userId << '\n';
	return os;
}