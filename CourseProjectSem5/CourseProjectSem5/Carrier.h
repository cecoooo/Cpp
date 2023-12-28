#pragma once
#include "CarrierCount.h";
#include <string>
#include <ostream>
using std::string;
using std::ostream;

class Carrier:public CarrierCount
{
private:
	int id;
	string type = "ab";
	string author = "ab";
	string title = "ab";
	int yearOfPublish = 0;
	int userId = 0;
public:
	Carrier();
	Carrier(string ty, string au, string ti, int y);
	~Carrier();
	int getId();
	string getType();
	string getAuthor();
	string getTitle();
	int getYearOfPublish();
	int getState();
	void setType(string ty);
	void setAuthor(string au);
	void setTitle(string ti);
	void setYearOfPublish(int y);
	void borrowCarrierByUserWithId(int id);
	string toString();
	friend ostream& operator<<(ostream& os, const Carrier& c);
};

