#include "CarrierDTO.h"

CarrierDTO::CarrierDTO(){}

CarrierDTO::CarrierDTO(int i, string ty, string au, string ti, int y, int ui)
{
	setId(i);
	setType(ty);
	setAuthor(au);
	setTitle(ti);
	setYearOfPublish(y);
	borrowCarrierByUserWithId(ui);
}

CarrierDTO::~CarrierDTO() {}

int CarrierDTO::getId()
{
	return this->id;
}

string CarrierDTO::getType()
{
	return this->type;
}

string CarrierDTO::getAuthor()
{
	return this->author;
}

string CarrierDTO::getTitle()
{
	return this->title;
}

int CarrierDTO::getYearOfPublish()
{
	return this->yearOfPublish;
}

int CarrierDTO::getState()
{
	return this->userId;
}

void CarrierDTO::setId(int i) 
{
	this->id = i;
}

void CarrierDTO::setType(string ty)
{
	this->type = ty;
}

void CarrierDTO::setAuthor(string au)
{
	this->author = au;
}

void CarrierDTO::setTitle(string ti)
{
	this->title = ti;
}

void CarrierDTO::setYearOfPublish(int y)
{
	this->yearOfPublish = y;
}

void CarrierDTO::borrowCarrierByUserWithId(int id)
{
	this->userId = id;
}

string CarrierDTO::toString()
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