// LISTING 8.7 - Creating a Stray Pointer
#include <iostream>

typedef unsigned short int USHORT;

int main()
{
    USHORT * pInt = new USHORT;
    *pInt = 10;
    std::cout << "*pInt: " << *pInt << std::endl;
    delete pInt;

    long * pLong = new long;
    *pLong = 90000;
    std::cout << "*pLong: " << *pLong << std::endl;

    *pInt = 20; // uh oh, this was deleted!

    std::cout << "*pInt: " << *pInt << std::endl;
    std::cout << "*pLong: " << *pLong << std::endl;
    delete pLong;

    return 0;
}