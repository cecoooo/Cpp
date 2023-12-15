#include "Functions.h"
#include <iostream>
#include <fstream>
#include <sstream>
using std::cout;

string Functions::readFromFile() 
{
	string line;
    string text = "";
	std::fstream MyReadFile("file.txt");
	while (getline(MyReadFile, line)) {
        text += line+'\n';
	}
    MyReadFile.close();
	return text;
}

void Functions::write(string info) 
{
    std::ofstream MyFile;
    MyFile.open("file.txt", std::ios::app);
    MyFile << info + '\n';

    MyFile.close();
}

string Functions::getAllPeopleByRegion(string region) 
{
    string input = readFromFile();
    string word = "";
    string region1;

    for (size_t i = 0; i < input.string::length(); i++)
    {
        if (input[i] == ' ' || input[i] == '\n')
        {
            if (word == "Region:") 
            {
                i++;
                while (input[i] != '\n') 
                {
                    region1 += input[i];
                }
                break;
            }
        }
        else
            word += input[i];
    }
    return region1;
}

void Functions::writeToFile(Person *person, Property *prop)
{
    write(person->toString());
    write(prop->toString());
    std::ofstream MyFile;
    MyFile.open("file.txt", std::ios::app);
    MyFile << '\n';
    MyFile.close();
}