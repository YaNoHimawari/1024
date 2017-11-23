// LISTING 3.5 A Demonstration of Adding Too Large a Number to a signed short Integer
#include <iostream>

int main()
{
    short int smallNumber;
    smallNumber = 32767;
    std::cout << "small number:" << smallNumber << std::endl;
    smallNumber++;
    std::cout << "small number:" << smallNumber << std::endl;
    smallNumber++;
    std::cout << "small number:" << smallNumber << std::endl;

    return 0;
}