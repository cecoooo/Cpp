#pragma once
#include <string>
#include "Address.h"
#include "Person.h"
#include "Property.h"
using std::string;

class Functions
{
private:
    static void write(string info);
public:
	static string readFromFile();
    static void writeToFile(Person *p, Property *pr);
    static string getAllPeopleByRegion(string region);
};

