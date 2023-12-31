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
}

void getAllFreeCarriers() 
{
    cout << "LIST OF ALL FREE CARRIERS" << endl;
    vector<CarrierDTO> freeCarriers = Library::getFreeCarriers();
    for (size_t i = 0; i < freeCarriers.size(); i++)
        cout << freeCarriers[i].toString();
    cout << "END OF THE LIST" << endl;
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
    cout << user.toString() << endl;
}

int main()
{
    cout << "-----LIBRARY-----\n" << endl;
    cout << "TO REGISTER A NEW USERS, PRESS '1'" << endl <<
        "TO INSERT A NEW CARRIERS, PRESS '2'" << endl <<
        "TO LOOK FOR A CARRIER, PRESS '3'" << endl <<
        "TO LOOK AT ALL FREE CARRIERS, PRESS '4'" << endl <<
        "TO GET A CARRIER FROM THE LIBRARY, PRESS '5'" << endl <<
        "TO GET INFORMATION FOR A USER, PRESS '6'" << endl <<
        "TO END THE PROGRAM, PRESS '0'" << endl;
    int initialInput;
    while (true) {
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


    /*Library::clearCarrierFile();
    Library::clearUserFile();
    User u("Ivan", 19, "0888123456");
    User u1("Alice", 25, "0777123456");
    User u2("Bob", 30, "0909123456");
    User u3("Eva", 22, "0555123456");
    User u4("Daniel", 28, "0666123456");
    User u5("Sophie", 35, "0999123456");
    User u6("Michael", 32, "0888123456");
    User u7("Olivia", 27, "0777123456");
    User u8("David", 40, "0909123456");
    User u9("Isabella", 19, "0555123456");
    User u10("James", 24, "0666123456");
    Carrier c("Book", "J.K.Rolling", "Harry Potter", 1999);
    Carrier c1("Movie", "Christopher Nolan", "Inception", 2010);
    Carrier c2("Music Album", "Taylor Swift", "1989", 2014);
    Carrier c3("Book", "George R.R. Martin", "A Game of Thrones", 1996);
    Carrier c4("Movie", "Quentin Tarantino", "Pulp Fiction", 1994);
    Carrier c5("Music Album", "Ed Sheeran", "Divide", 2017);
    Carrier c6("Book", "Agatha Christie", "Murder on the Orient Express", 1934);
    Carrier c7("Movie", "Greta Gerwig", "Little Women", 2019);
    Carrier c8("Music Album", "Beyonce", "Lemonade", 2016);
    Carrier c9("Book", "Harper Lee", "To Kill a Mockingbird", 1960);
    Carrier c10("Movie", "Steven Spielberg", "Jurassic Park", 1993);
    Library::borrowCarrierWithUser(1, 1);
    Library::borrowCarrierWithUser(1, 2);
    for (size_t i = 0; i < Library::getCarriers().size(); i++)
    {
        cout << Library::getCarriers()[i].toString() << endl;
    }
    for (size_t i = 0; i < Library::getUsers().size(); i++)
    {
        cout << Library::getUsers()[i].toString() << endl;
    }*/
};