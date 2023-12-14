#include "Property.h"
#include <string>

Property::Property(){}

Property::Property(Address adr, int rm, double pr, bool rnt) 
{
    address = adr;
    rooms = rm;
    price = pr;
    isForRent = rnt;
}

Property::~Property() {}

Address Property::getAddress(){
    return address;
}

int Property::getRooms(){
    return rooms;
}

double Property::getPrice() {
    return price;
}

bool Property::getIsItForRent() 
{
    return isForRent;
}

void Property::setAddress(Address addr) {
    address = addr;
}

void Property::setRooms(int rms) {
    rooms = rms;
}

void Property::setPrice(double prc) {
    price = prc;
}
void Property::setIsItForRent(bool rnt)
{
    isForRent = rnt;
}

/*Address address;
    int rooms;
    double price;
    bool isForRent;*/

string Property::toString()
{
    string forSaleOrRent;
    if (isForRent)
        forSaleOrRent = "For Sale";
    else
        forSaleOrRent = "For Rent";
    
    return "PROPERTY DATA\n" + address.toString() + '\n'
        + "Number of rooms: " + std::to_string(rooms) + '\n'
        + "Price: " + std::to_string(price) + '\n'
        + forSaleOrRent;
}

std::ostream& operator<<(std::ostream& os, const Property& prop) {
    os << "Rooms: " << prop.rooms << std::endl;
    os << "Price: $" << prop.price << std::endl;
    os << "For Rent: " << (prop.isForRent ? "Yes" : "No") << std::endl;
    return os;
}