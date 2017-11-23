// LISTING 8.3 - Finding Out What Is Stored in Pointers
#include <iostream>

int main()
{
    using namespace std;

    unsigned short int myAge = 5, yourAge = 10;

    // a pointer
    unsigned short int * pAge = &myAge;

    cout << "myAge:\t" << myAge
        << "\t\tyourAge:\t" << yourAge << endl;

    cout << "&myAge:\t" << &myAge
        << "\t&yourAge:\t" << &yourAge << endl;

    cout << "pAge:\t" << pAge << endl;
    cout << "*pAge:\t" << *pAge << endl;

    cout << "\nReassigning: pAge = &yourAge..." << endl << endl;
    pAge = &yourAge; // reassign the pointer

    cout << "myAge:\t" << myAge <<
        "\t\tyourAge:\t" << yourAge << endl;

    cout << "&myAge:\t" << &myAge
        << "\t&yourAge:\t" << &yourAge << endl;

    cout << "pAge:\t" << pAge << endl;
    cout << "*pAge:\t" << *pAge << endl;

    cout << "\n&pAge:\t" << &pAge << endl;

    return 0;
}