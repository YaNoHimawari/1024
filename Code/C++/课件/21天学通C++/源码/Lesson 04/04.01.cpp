// LISTING 4.1 - Using an Integer Array
#include <iostream>

int main()
{
    int myArray[5]; // Array of 5 integers
    int i;

    for ( i=0; i<5; i++) // 0-4
    {
        std::cout << "Value for myArray[" << i << "]: ";
        std::cin >> myArray[i];
    }

    for (i = 0; i<5; i++)
        std::cout << i << ": " << myArray[i] << std::endl;

    return 0;
}