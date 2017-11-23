// LISTING 6.5 - Demonstrating Global and Local Variables
#include <iostream>

void myFunction(); // prototype
int x = 5, y = 7; // global variables

int main()
{
    using namespace std;

    cout << "x from main: " << x << endl;
    cout << "y from main: " << y << endl << endl;
    myFunction();
    cout << "Back from myFunction!" << endl << endl;
    cout << "x from main: " << x << endl;
    cout << "y from main: " << y << endl;

    return 0;
}

void myFunction()
{
    using std::cout;

    int y = 10;

    cout << "x from myFunction: " << x << std::endl;
    cout << "y from myFunction: " << y << std::endl << std::endl;
}