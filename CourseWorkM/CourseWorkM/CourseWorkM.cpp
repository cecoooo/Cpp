#include <iostream>
#include "Person.h"
#include <string>;
#include "Functions.h"
#include "Property.h"
using std::strcpy;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "HELLO! THIS IS OUR SYSTEM FOR PROPERTIES AND CLIENTS" << endl;
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