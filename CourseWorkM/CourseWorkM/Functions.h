#pragma once
#include <string>
using std::string;

class Functions
{
public:
	static string readFromFile();
	static void writeToFile(string info);
    static string getAllPeopleByRegion(string region);
};

