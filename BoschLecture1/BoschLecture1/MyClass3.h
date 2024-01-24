#pragma once
#include <iostream>
using std::cout;
using std::endl;

class MyClass3
{
private:
	int *a;
public:
    MyClass3() =default;
    MyClass3(MyClass3&& source)
        : a{ source.a }
    {

        cout << "Move Constructor for "
            << *source.a << endl;
        source.a = nullptr;
    }
    void setA(int* a) 
    {
        this->a = a;
    }
};

