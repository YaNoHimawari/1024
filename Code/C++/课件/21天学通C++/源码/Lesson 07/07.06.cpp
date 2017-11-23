// LISTING 7.6 - Skipping the Body of the while Loop
#include <iostream>

int main()
{
    int counter;

    std::cout << "How many hellos?: ";
    std::cin >> counter;
    while (counter > 0)
    {
        std::cout << "Hello!\n";
        counter--;
    }
    std::cout << "Counter is OutPut: " << counter;

    return 0;
}