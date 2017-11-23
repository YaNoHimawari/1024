// LISTING 7.5 - while(true) Loops
#include <iostream>

int main()
{
    int counter = 0;

    while (true)
    {
        counter ++;
        if (counter > 10)
            break;
    }
    std::cout << "Counter: " << counter << std::endl;
    return 0;
}