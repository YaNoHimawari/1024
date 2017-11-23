// LISTING 5.2 - A Demonstration of Subtraction and Integer Overflow

// integer overflow
#include <iostream>

int main()
{
    using std::cout;
    using std::endl;

    unsigned int difference;
    unsigned int bigNumber = 100;
    unsigned int smallNumber = 50;

    difference = bigNumber - smallNumber;
    cout << "Difference is: " << difference;

    difference = smallNumber - bigNumber;
    cout << "\nNow difference is: " << difference <<endl;

    return 0;
}