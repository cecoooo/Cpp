#include <iostream>
#include "User.h"
#include "Carrier.h"
#include "Library.h"
using std::cout;
using std::endl;

int main()
{
    Library::clearCarrierFile();
    Library::clearUserFile();
    User u("Ivan", 19, "0888123456");
    User u1("Ne e Ivan", 19, "0888123456");
    User u2("Gosho", 19, "0888123456");
    User u3("Pesjo", 19, "0888123456");
    User u4("Misho", 19, "0888123456");
    User u5("Ivan1", 19, "0888123456");
    User u6("Ivan2", 19, "0888123456");
    Carrier c("Book", "J.K.Rolling", "Harry Potter", 1999);
    Carrier c1("Book", "J.K.Rolling", "Harry Potter", 1999);
    Carrier c2("CD", "J.K.Rolling", "Harry Potter", 1999);
    Carrier c3("DVD", "J.K.Rolling", "Harry Potter", 1999);
    Carrier c4("CD-ROM", "J.K.Rolling", "Harry Potter", 1999);
    Carrier c5("CD-Ciganin", "J.K.Rolling", "Harry Potter", 1999);
    Carrier c6("Audio Book", "J.K.Rolling", "Harry Potter", 1999);
    Library::borrowCarrierWithUser(1, 6);
    Library::borrowCarrierWithUser(1, 7);
    /*for (size_t i = 0; i < Library::getCarriers().size(); i++)
    {
        cout << Library::getCarriers()[i].toString() << endl;
    }
    for (size_t i = 0; i < Library::getUsers().size(); i++)
    {
        cout << Library::getUsers()[i].toString() << endl;
    }*/
}