#include "Functions.h"
#include "Property.h"
#include "Person.h"
#include "Address.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::istringstream;
using std::vector;

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

void Functions::writeToFile(Person *person, Property *prop)
{
    write(person->toString());
    write(prop->toString());
    std::ofstream MyFile;
    MyFile.open("file.txt", std::ios::app);
    MyFile << '\n';
    MyFile.close();
}

void Functions::ImportPersonAndProperty()
{
    while (true)
    {
        cout << "PERSON DATA" << endl;
        string clientName, egn, country, town, street;
        int number;
        cout << "Enter client name: ";
        cin >> clientName;
        cout << "Enter client EGN: ";
        cin >> egn;
        cout << "--Place Of Residence--" << endl;
        cout << "Country: ";
        cin >> country;
        cout << "Town: ";
        cin >> town;
        cout << "Street: ";
        cin >> street;
        cout << "Number: ";
        cin >> number;
        cout << endl << "PROPERTY DATA" << endl;
        int rooms, numberPr;
        double price;
        bool isForRent = true;
        char yORn;
        string countryPr, townPr, streetPr, region;
        cout << "Number Of Rooms: ";
        cin >> rooms;
        cout << "Price: ";
        cin >> price;
        cout << "Is it for sale(y/n): ";
        cin >> yORn;
        if (yORn == 'n')
            isForRent = false;
        cout << "--Location--" << endl;
        cout << "Region: ";
        cin >> region;
        cout << "Country: ";
        cin >> countryPr;
        cout << "Town: ";
        cin >> townPr;
        cout << "Street: ";
        cin >> streetPr;
        cout << "Number: ";
        cin >> numberPr;
        cout << endl;
        Address* addressPerson = new Address(country, town, street, number);
        Address* addressProperty = new Address(region, countryPr, townPr, streetPr, numberPr);
        Person* person = new Person(clientName, egn, *addressPerson);
        Property* prop = new Property(*addressProperty, rooms, price, isForRent);
        Functions::writeToFile(person, prop);
        cout << "Do you want to stop? (y/n)";
        cin >> yORn;
        if (yORn == 'y')
            break;

    }
}

void Functions::printAllPeopleByRegion()
{
    cout << "Enter Region: " << endl;
    string region;
    cin >> region;
    cout << endl;

    string input = readFromFile();
    
    std::vector<std::string> records;
    size_t start = 0, found;

    while ((found = input.find("\n\n", start)) != std::string::npos) {
        records.push_back(input.substr(start, found - start));
        start = found + 2; 
    }

    for (const auto& record : records) {
        size_t personDataPos = record.find("PERSON DATA");
        size_t propertyDataPos = record.find("PROPERTY DATA");

        if (personDataPos != std::string::npos && propertyDataPos != std::string::npos) {
            size_t regionPos = record.find("Region: "+region, propertyDataPos);

            if (regionPos != std::string::npos) {
                std::cout << record.substr(personDataPos, propertyDataPos - personDataPos) << std::endl;
            }
        }
    }

}

void Functions::printPropertiesByEGN() 
{
    cout << "Enter EGN: " << endl;
    string targetEGN;
    cin >> targetEGN;
    cout << endl;

    string input = readFromFile();

    std::istringstream iss(input);
    std::string line;

    while (std::getline(iss, line)) {
        if (line.find("EGN: 1234567890") != std::string::npos) {
            std::getline(iss, line); 
            std::getline(iss, line); 
            std::cout << "Region: " << line << std::endl;

            std::getline(iss, line);
            std::cout << "Address: " << line << std::endl;


            std::getline(iss, line);
            std::cout << "Number of rooms: " << line << std::endl;


            std::getline(iss, line);
            std::cout << "Price: " << line << std::endl;
            cout << "-----------" << endl;
        }
    }
}