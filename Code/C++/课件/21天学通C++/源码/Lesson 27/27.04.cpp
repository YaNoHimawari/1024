// Listing 17.4 - Using get() with no parameters

#include <iostream>

int main()
{
    char ch;
    while ( (ch = std::cin.get()) != EOF)
    {
      std::cout << "ch: " << ch << std::endl;
    }
    std::cout << "\nDone!\n";
    return 0;
}
