#pragma once
#include <string>
#include <vector>
using std::string;
using std::vector;

class UserDTO
{
private:
	int id;
	string name;
	int age;
	string phone;
	vector<int> carrierIds;
public:
	UserDTO();
	UserDTO(int i, string n, int a, string ph);
	~UserDTO();
	int getId();
	string getName();
	int getAge();
	string getPhone();
	vector<int> getCarrierIds();
	void setId(int i);
	void setName(string n);
	void setAge(int a);
	void setPhone(string p);
	void borrowCarrier(int c);
	string toString();
};

