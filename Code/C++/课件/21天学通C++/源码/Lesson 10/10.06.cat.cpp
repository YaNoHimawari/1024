// LISTING 10.6 - Cat Implementation in Cat.cpp
#include "10.05.Cat.h"

Cat::Cat(int initialAge) //constructor
{
    itsAge = initialAge;
}

Cat::~Cat() //destructor, takes no action
{
}

// Create a cat, set its age, have it
// meow, tell us its age, then meow again.
int main()
{
    Cat Frisky(5);
    Frisky.Meow();
    std::cout << "Frisky is a cat who is " ;
    std::cout << Frisky.GetAge() << " years old.\n";
    Frisky.Meow();
    Frisky.SetAge(7);
    std::cout << "Now Frisky is " ;
    std::cout << Frisky.GetAge() << " years old.\n";

    return 0;
}