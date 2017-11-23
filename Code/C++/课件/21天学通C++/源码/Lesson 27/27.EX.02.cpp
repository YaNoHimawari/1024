#include <iostream>
int main()
{
    char name[80];
    std::cout << "Enter your full name: ";
    std::cin.getline(name,80);
    std::cout << "\nYou entered: " << name << std::endl;
    return 0;
}