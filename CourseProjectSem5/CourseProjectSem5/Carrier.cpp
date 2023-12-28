#include "Carrier.h"

//Carrier();
//Carrier(string ty, string au, string ti, int y, bool s);
//~Carrier();
//string getType();
//string getAuthor();
//string getTitle();
//int getYearOfPublish();
//bool getState();
//void setType(string ty);
//void setAuthor(string au);
//void setTitle(string ti);
//void setYearOfPublish(int y);
//void setState(bool s);

Carrier::Carrier() 
{
	CarrierCount::increaseCarrierCount();
	this->id = CarrierCount::getCarrierCount();
}

Carrier::Carrier(string ty, string au, string ti, int y, bool s)
{
	CarrierCount::increaseCarrierCount();
	this->id = CarrierCount::getCarrierCount();
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

bool Carrier::getState()
{
	return this->state;
}