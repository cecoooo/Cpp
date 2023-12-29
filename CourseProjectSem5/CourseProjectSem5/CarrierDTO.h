#pragma once
#include <string>
using std::string;

class CarrierDTO
{
private:
	int id;
	string type;
	string author;
	string title;
	int yearOfPublish;
	int userId;
public:
	CarrierDTO();
	CarrierDTO(int i, string ty, string au, string ti, int y, int ui);
	~CarrierDTO();
	int getId();
	string getType();
	string getAuthor();
	string getTitle();
	int getYearOfPublish();
	int getState();
	void setId(int i);
	void setType(string ty);
	void setAuthor(string au);
	void setTitle(string ti);
	void setYearOfPublish(int y);
	void borrowCarrierByUserWithId(int id);
	string toString();
};

