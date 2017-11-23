// LISTING 10.1 - Accessing the Public Members of a Simple Class
#include <iostream>

class Cat // declare the Cat class
{
public: // members that follow are public
    int itsAge; // member variable
    int itsWeight; // member variable
}; // note the semicolon

int main()
{
    Cat Frisky;
    Frisky.itsAge = 5; // assign to the member variable
    std::cout << "Frisky is a cat who is " ;
    std::cout << Frisky.itsAge << " years old.\n";

    return 0;
}