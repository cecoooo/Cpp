#include <iostream>
#include "Temperature.h"
#include "Celsius.h"

int main()
{
    Celsius* temp = new Celsius(12);
    std::cout << "Temperature to Fahrenheit: " << temp->ConvertToFahrenheit();
}