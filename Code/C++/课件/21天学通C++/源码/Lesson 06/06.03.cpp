// LISTING 6.3 - Variables Scoped Within a Block
#include <iostream>

void myFunc();

int main()
{
    int x = 5;
    std::cout << "\nIn main x is: " << x;

    myFunc();

    std::cout << "\nBack in main, x is: " << x;
    return 0;
}

void myFunc()
{
    int x = 8;
    std::cout << "\nIn myFunc, local x: " << x << std::endl;

    {
        std::cout << "\nIn block in myFunc, x is: " << x;

        int x = 9;

        std::cout << "\nVery local x: " << x;
    }

    std::cout << "\nOut of block, in myFunc, x: " << x << std::endl;
}