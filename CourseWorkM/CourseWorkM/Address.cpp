#include "Address.h"
#include <string>

Address::Address(){}

Address::Address(string cnt, string twn, string str, int num)
{
    this->country = cnt;
    this->town = twn;
    this->street = str;
    this->number = num;
}

Address::Address(string area, string cnt, string twn, string str, int num) : Region(area)
{
    this->setArea(area);
    this->country = cnt;
    this->town = twn;
    this->street = str;
    this->number = num;
}

Address::~Address() {}

string Address::getCountry() {
    return country;
}

string Address::getTown() {
    return town;
}

string Address::getStreet() {
    return street;
}

int Address::getNumber() {
    return number;
}

void Address::setCountry(std::string newCountry) {
    country = newCountry;
}

void Address::setTown(std::string newTown) {
    town = newTown;
}

void Address::setStreet(std::string newStreet) {
    street = newStreet;
}

void Address::setNumber(int newNumber) {
    number = newNumber;
}

string Address::toString() 
{
    return country + ", " + town + ", " + street + ", " + std::to_string(number) + 
        " " + "Region: " + this->getArea();
}

std::ostream& operator<<(std::ostream& os, const Address& address) {
    os << "Country: " << address.country << ", Town: " << address.town
        << ", Street: " << address.street << ", Number: " << address.number;
    return os;
}