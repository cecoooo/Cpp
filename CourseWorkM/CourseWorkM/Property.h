#pragma once
#include "Address.h"
#include <iostream>
using std::string;

class Property {
private:
    Address address;
    int rooms;
    double price;
    bool isForRent;

public:
    Property();
    Property(Address adr, int rm, double pr, bool rnt);
    ~Property();
    Address getAddress();
    int getRooms();
    double getPrice();
    bool getIsItForRent();
    void setAddress(Address addr);
    void setRooms(int rms);
    void setPrice(double prc);
    void setIsItForRent(bool rnt);
    string toString();
    friend std::ostream& operator<<(std::ostream& os, const Property& prop);
};
