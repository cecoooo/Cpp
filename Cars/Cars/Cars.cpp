#include <iostream>
#include "Car.h"
#include "RentACar.h"

int main()
{
    RentACar car("GOLF", 2010, "CA1234BB", 4.50);
    std::cout << car.toString();

}