#include "Functions.h"
#include <iostream>
#include <fstream>
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

void Functions::writeToFile(string info) 
{
    std::ofstream MyFile;
    MyFile.open("file.txt", std::ios::app);
    MyFile << info + '\n';

    MyFile.close();
}

//string Functions::getAllPeopleByRegion(string region) 
//{
//    
//}