#include <iostream>
#include "User.h"
#include"CarrierCount.h"
#include"Carrier.h"
using std::cout;

int main()
{
    User user;
    user.setName("Ij");
    user.setAge(14);
    user.setPhone("1234567890");
    cout << user.toString();
    User user1;
    user1.setName("Ij");
    user1.setAge(14);
    user1.setPhone("1234567890");
    cout << user1.toString();
    User user2;
    user2.setName("Ij");
    user2.setAge(14);
    user2.setPhone("1234567890");
    cout << user2.toString();
}