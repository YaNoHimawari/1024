// LISTING 4.5 - Filling an Array
#include <iostream>

int main()
{
    char buffer[80] = {'\0'}; 7: std::cout << "Enter the string: ";
    std::cin >> buffer;
    std::cout << "Here's the buffer: " << buffer << std::endl;
    return 0;
}