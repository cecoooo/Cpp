#include <iostream>
#include "Person.h"
#include <string>;
#include "Functions.h"
#include "Property.h"


using std::strcpy;
using std::cin;
using std::cout;

int main()
{
    Address* address = new Address("East Europe", "Bulgaria", "Plovdiv", "Ivan Vazov", 30);
    Person *person = new Person("Ivan", "1234567890", *address);
    Address* lookingForAddress = new Address("East Europe", "Bulgaria", "Sofia", "Lozenec", 12);
    Property* prop = new Property(*lookingForAddress, 5, 5000000.00, false);
    Functions* func = new Functions();
    func->writeToFile(person->toString());
    func->writeToFile(prop->toString());
    cout << func->readFromFile();
}