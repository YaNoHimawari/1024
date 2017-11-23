// LISTING 8.2 - Manipulating Data by Using Pointers
#include <iostream>

typedef unsigned short int USHORT;

int main()
{

    using namespace std;

    USHORT myAge; // a variable
    USHORT * pAge = 0; // a pointer

    myAge = 5;

    cout << "myAge: " << myAge << endl;
    pAge = &myAge; // assign address of myAge to pAge
    cout << "*pAge: " << *pAge << endl << endl;

    cout << "Setting *pAge = 7... " << endl;
    *pAge = 7; // sets myAge to 7

    cout << "*pAge: " << *pAge << endl;
    cout << "myAge: " << myAge << endl << endl;

    cout << "Setting myAge = 9... " << endl;
    myAge = 9;

    cout << "myAge: " << myAge << endl;
    cout << "*pAge: " << *pAge << endl;

    return 0;
}