// LISTING 7.16 Demonstrating the switch Statement
#include <iostream>

int main()
{
    using namespace std;

    unsigned short int number;
    cout << "Enter a number between 1 and 5: ";
    cin >> number;

    switch (number)
    {
    case 0: cout << "Too small, sorry!";
        break;
    case 5: cout << "Good job! " << endl; // fall through
    case 4: cout << "Nice Pick!" << endl; // fall through
    case 3: cout << "Excellent!" << endl; // fall through
    case 2: cout << "Masterful!" << endl; // fall through
    case 1: cout << "Incredible!" << endl;
        break;
    default: cout << "Too large!" << endl;
        break;
    }
    cout << endl << endl;

    return 0;
}