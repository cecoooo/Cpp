#include <iostream>
#include "Person.h"
#include <string>;
#include "AddressHolder.h"
using std::strcpy;
using std::cin;

int main()
{
    Person *person = new Person();
    char* adr = (char*)malloc(16);
    strcpy_s(adr,16, "Studentski grad");
    person->setName("ivan");
    person->setEGN("1234567890");
    person->setAddress(adr, 16);
    person->~Person();
   

    AddressHolder* ah = new AddressHolder();
    ah->addAddress(adr, 16);
    ah->addAddress(adr, 16);
    ah->addAddress(adr, 16);
    ah->addAddress(adr, 16);
    ah->addAddress(adr, 16);
    ah->addAddress(adr, 16);
    ah->~AddressHolder();
    free(adr);
    adr = NULL;
}