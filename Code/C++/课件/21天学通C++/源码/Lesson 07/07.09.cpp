// LISTING 7.9 - Demonstrating the for Loop
#include <iostream>

int main()
{
    int counter;
    for (counter = 0; counter < 5; counter++)
        std::cout << "Looping! ";

    std::cout << "\nCounter: " << counter << std::endl;
    return 0;
}