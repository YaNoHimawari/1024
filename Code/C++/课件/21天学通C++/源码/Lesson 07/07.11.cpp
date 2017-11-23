// LISTING 7.11 - Null Statements in for Loops
#include <iostream>

int main()
{
    int counter = 0;

    for( ; counter < 5; )
    {
        counter++;
        std::cout << "Looping! ";
    }

    std::cout << "\nCounter: " << counter << std::endl;
    return 0;
}