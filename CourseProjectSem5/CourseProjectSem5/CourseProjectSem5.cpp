#include <iostream>
#include "User.h"
#include "Carrier.h"
#include "Library.h"
using std::cout;
using std::cin;
using std::endl;


void registerNewUser() 
{
    cout << "ENTER USER DATA." << endl;
    string name, phone;
    int age;
    cout << "Name: ";
    cin >> name;
    cout << "Phone: ";
    cin >> phone;
    cout << "Age: ";
    cin >> age;
    User user(name, age, phone);
    cout << "--USER REGISTERED SUCCESSFULLY--" << endl;
}

void insertNewCarrier()
{
    cout << "ENTER CARRIER DATA." << endl;
    string type, author, title;
    int year;
    cout << "Type: ";
    cin >> type;
    cout << "Author: ";
    cin >> author;
    cout << "Title: ";
    cin >> title;
    cout << "Year: ";
    cin >> year;
    Carrier carrier(type, author, title, year);
    cout << "--CARRIER REGISTERED SUCCESSFULLY--" << endl;
}

void lookForCarrier() 
{
    cout << "WHAT DO YOU WANT TO SEARCH BY?" << endl <<
        "For Type, press '1'" << endl << 
        "For Author, press '2'" << endl << 
        "for Title press '3'" << endl << 
        "for Year, press '4'" << endl << 
        "To stop the process, press '0'" << endl;
    int initialInput;
    while (true)
    {
        cin >> initialInput;
        vector<CarrierDTO> carriersAll = Library::getCarriers();
        bool isThereData = true;
        if(initialInput == 1){
            string command;
            cout << "Enter Type: ";
            cin >> command;
            for (size_t i = 0; i < carriersAll.size(); i++) {
                if (carriersAll[i].getType() == command) {
                    cout << carriersAll[i].toString() << endl; 
                    isThereData = false;
                }
            }
            if (isThereData)
                cout << "No Carrier of that type found in the Library." << endl;
        }
        else if (initialInput == 2) {
            string command;
            cout << "Enter Author: ";
            cin >> command;
            for (size_t i = 0; i < carriersAll.size(); i++) {
                if (carriersAll[i].getAuthor() == command) {
                    cout << carriersAll[i].toString() << endl;
                    isThereData = false;
                }
            }
            if (isThereData)
                cout << "No Carrier with this author found in the Library." << endl;
        }
        else if (initialInput == 3) {
            string command;
            cout << "Enter Title: ";
            cin >> command;
            for (size_t i = 0; i < carriersAll.size(); i++) {
                if (carriersAll[i].getTitle() == command) {
                    cout << carriersAll[i].toString() << endl;
                    isThereData = false;
                }
            }
            if (isThereData)
                cout << "No Carrier with title like that found in the Library." << endl;
        }
        else if (initialInput == 4) {
            int command;
            cout << "Enter Year: ";
            cin >> command;
            for (size_t i = 0; i < carriersAll.size(); i++) {
                if (carriersAll[i].getYearOfPublish() == command) {
                    cout << carriersAll[i].toString() << endl;
                    isThereData = false;
                }
            }
            if (isThereData)
                cout << "No Carrier published in this year found in the Library." << endl;
        }
        else if (initialInput == 0)
            break;
        else
            cout << "UNRECOGNIZED COMMAND. TRY AGAIN." << endl;
    }
    cout << "--PROCESS STOPPED--" << endl;
}

void getAllFreeCarriers() 
{
    cout << "--LIST OF ALL FREE CARRIERS--" << endl;
    vector<CarrierDTO> freeCarriers = Library::getFreeCarriers();
    for (size_t i = 0; i < freeCarriers.size(); i++)
        cout << freeCarriers[i].toString();
    cout << "--END OF THE LIST--" << endl;
}

void getCarrierFromTheLibrary() 
{
    cout << "GET CARRIER FROM THE LIBRARY" << endl;
    UserDTO user;
    while (!user.getId()) 
    {
        cout << "Enter your phone: ";
        string ph;
        cin >> ph;
        user = Library::getUserByPhone(ph);
    }
    CarrierDTO carr;
    while (true) {
        string ti, au;
        cout << "Title: ";
        cin >> ti;
        cout << "Author: ";
        cin >> au;
        vector<CarrierDTO> carriers = Library::getCarriers();
        bool isThereCarrier = true;
        for (size_t i = 0; i < carriers.size(); i++)
        {
            if (carriers[i].getTitle() == ti || carriers[i].getAuthor() == au) {
                carr = carriers[i];
                isThereCarrier = false;
                break;
            }
        }
        if (isThereCarrier) {
            cout << "No Carrier found with this title or author.\nDo you want to try again?(y/n)" << endl;
            string answ;
            cin >> answ;
            if (answ != "y" || answ != "yes")
                break;
        }
        else
            break;
    }
    if (!carr.getState())
        cout << "You have successfully borrowed carrier from the Library." << endl <<
        "-DESCRIPTION OF CARRIER-" << endl <<
        carr.toString();
    Library::borrowCarrierWithUser(user.getId(), carr.getId());
}

void getInformationForUser()
{
    cout << "GET INFORMATION FOR A USER." << endl;
    UserDTO user;
    while (!user.getId())
    {
        cout << "Enter phone number: ";
        string ph;
        cin >> ph;
        user = Library::getUserByPhone(ph);
    }
    cout << "--INFO--\n" << user.toString() << endl;
}

int main()
{
    cout << "-----LIBRARY-----\n" << endl;
    int initialInput;
    while (true) {
        cout << "TO REGISTER A NEW USERS, PRESS '1'" << endl <<
            "TO INSERT A NEW CARRIERS, PRESS '2'" << endl <<
            "TO LOOK FOR A CARRIER, PRESS '3'" << endl <<
            "TO LOOK AT ALL FREE CARRIERS, PRESS '4'" << endl <<
            "TO GET A CARRIER FROM THE LIBRARY, PRESS '5'" << endl <<
            "TO GET INFORMATION FOR A USER, PRESS '6'" << endl <<
            "TO END THE PROGRAM, PRESS '0'" << endl;
        cin >> initialInput;
        if (initialInput == 1)
        {
            registerNewUser();
        }
        else if (initialInput == 2)
        {
            insertNewCarrier();
        }
        else if (initialInput == 3)
        {
            lookForCarrier();
        }
        else if (initialInput == 4)
        {
            getAllFreeCarriers();
        }
        else if (initialInput == 5)
        {
            getCarrierFromTheLibrary();
        }
        else if (initialInput == 6)
        {
            getInformationForUser();
        }
        else if (initialInput == 0)
            break;
        else
            cout << "UNRECOGNIZED COMMAND. TRY AGAIN." << endl;
    }
    cout << "PROGRAM ENDS SUCCESSFULLY.";
    return 0;
};