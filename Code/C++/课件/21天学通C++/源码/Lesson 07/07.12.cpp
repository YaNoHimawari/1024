// LISTING 7.12 - Illustrating an Empty for Loop Statement
#include <iostream>

int main()
{
    int counter=0; // initialization
    int max;
    std::cout << "How many hellos? ";
    std::cin >> max;
    for (;;) // a for loop that doesn't end
    {
        if (counter < max) // test
        {
            std::cout << "Hello! " << std::endl;
            counter++; // increment
        }
        else
            break;
    }

    return 0;
}