#include <iostream>
int main()
{
    int x;
    std::cout << "Enter a number: ";
    std::cin >> x;
    std::cout << "You entered: " << x << std::endl;
    std::cerr << "Uh oh, this to cerr!" << std::endl;
    std::clog << "Uh oh, this to clog!" << std::endl;
    return 0;
}