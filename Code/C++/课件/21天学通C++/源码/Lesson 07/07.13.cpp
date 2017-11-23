// LISTING 7.13 - Illustrates the Null Statement in a for Loop
#include <iostream>

int main()
{
    for (int i = 0; i<5; std::cout << "i: " << i++ << std::endl)
        ;    // Null-Statement

    return 0;
}