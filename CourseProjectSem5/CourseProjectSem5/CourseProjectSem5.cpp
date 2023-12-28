#include <iostream>
#include "User.h"
#include "Carrier.h"
#include "Library.h"
using std::cout;
using std::endl;

int main()
{
    User u("Ivan", 19, "0888123456");
    cout << u;
    Carrier c("Book", "J.K.Rolling", "Harry Potter", 1999);
    cout << c;
    Carrier c1("Book", "J.K.Rolling", "Harry Potter", 1999);
    Carrier c2("CD", "J.K.Rolling", "Harry Potter", 1999);
    Carrier c3("DVD", "J.K.Rolling", "Harry Potter", 1999);
    Carrier c4("CD-ROM", "J.K.Rolling", "Harry Potter", 1999);
    Carrier c5("CD-Ciganin", "J.K.Rolling", "Harry Potter", 1999);
    Carrier c6("Audio Book", "J.K.Rolling", "Harry Potter", 1999);
    for (size_t i = 0; i < Library::getCarriers().size(); i++)
    {
        cout << Library::getCarriers()[i].toString() << endl;
    }
}