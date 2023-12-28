#pragma once
#include "CarrierCount.h";
#include <string>
using std::string;

class Carrier:public CarrierCount
{
private:
	int id;
	string type;
	string author;
	string title;
	int yearOfPublish;
	bool state;
public:
	Carrier();
	Carrier(string ty, string au, string ti, int y, bool s);
	~Carrier();
	int getId();
	string getType();
	string getAuthor();
	string getTitle();
	int getYearOfPublish();
	bool getState();
	void setType(string ty);
	void setAuthor(string au);
	void setTitle(string ti);
	void setYearOfPublish(int y);
	void setState(bool s);
};

