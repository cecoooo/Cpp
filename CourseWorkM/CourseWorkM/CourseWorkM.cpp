#include <iostream>
#include <string>;
#include "Functions.h"
using std::strcpy;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "HELLO! THIS IS OUR SYSTEM FOR PROPERTIES AND CLIENTS." << endl
        << "WHAT DO YOU WANT TO DO?" << endl;
    int input;
    while (true) {
        cout << "INSERT PERSON AND PROPERTY (PRESS '1')" << endl
            << "LOOK FOR PEOPLE BY REGION (PRESS '2')" << endl
            << "LOOK FOR PROPERTIES BY GIVEN PERSON (PRESS '3')" << endl
            << "FOR EXIT PRESS '0'" << endl
            << "INITIAL INPUT: ";
        cin >> input;
        cout << endl << "-----------" << endl;
        switch (input)
        {
        case 1: Functions::ImportPersonAndProperty(); break;
        case 2: Functions::printAllPeopleByRegion(); break;
        case 3: Functions::printPropertiesByEGN(); break;
        case 0: break;
        default:
            cout << "Invalid input. Try again" << endl;
            break;
        }
        if (input == 0)
            break;
        cout << "-----------" << endl;
    }
    cout << "PROGRAM EXECUTED." << endl;
}