#include <iostream>
using namespace std;

class MyClass 
{
public:
    int x;
    mutable int y;
};

consteval int func2(int a, int b) 
{
    return a + b;
}

constexpr int func(int x, int y) 
{
    return x * y;
}

int func1(int x, int y)
{
    return x * y;
}


int main()
{
    int n, m;
    cin >> n >> m;
    const int a = n;
    // constexpr b = n; // error - consetxpression must have const rvalue
    //cout << func(n, m);
    int arr[func(3,4)]; // constexpression function let to determine array size in compile time
    const int c = func2(2, 3);
    cout << c << endl;
    int d = func2(2, 3);
    const int e=2, f=3;
    int g = func2(e,f);
    //int d = func2(m, 3); error - consteval function must accept only const parameters
    cout << d << endl;

    const MyClass myClass;
    //myClass.x = 1; // error - object is const and 'x' is not a mutable type, so value could not be changed
    myClass.y = 2; // 'y' is mutable a could be changed even if object is decalred const
}

// *bonus info: 'volatile' type qualifier:
// A type you can use to daclare that an object can be modified in the program by the hardware