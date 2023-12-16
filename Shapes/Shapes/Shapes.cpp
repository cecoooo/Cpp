#include <iostream>
#include "Circle.h"

void getCirclesWithRadiusBiggerThan10(Circle arr[5]);
int main()
{
    Circle circleArr[5];
    Point point1(1, 1, 'A');
    Point point2(2, 2, 'B');
    Point point3(3, 3, 'C');
    Point point4(4, 4, 'D');
    Point point5(5, 5, 'E');
    Circle circle1(point1, 5);
    Circle circle2(point2, 20);
    Circle circle3(point3, 10);
    Circle circle4(point4, 15);
    Circle circle5(point5, 7);

    circleArr[0] = circle1;
    circleArr[1] = circle2;
    circleArr[2] = circle3;
    circleArr[3] = circle4;
    circleArr[4] = circle5;

    getCirclesWithRadiusBiggerThan10(circleArr);
}

void getCirclesWithRadiusBiggerThan10(Circle arr[5])
{
    for (size_t i = 0; i < 5; i++) 
        if (arr[i].getRadius() > 10) 
            arr[i].getInfo();
}