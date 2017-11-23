// LISTING 7.8 - while Reexamined
#include <iostream>

int main()
{
    int counter = 0;

    while(counter < 5)
    {
        counter++;
        std::cout << "Looping! ";
    }

    std::cout << "\nCounter: " << counter << std::endl;
    return 0;
}