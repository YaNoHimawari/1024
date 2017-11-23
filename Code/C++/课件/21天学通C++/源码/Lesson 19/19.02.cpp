// LISTING 19.2 - Inserting Elements in the List Using push_front
#include <list>
#include <iostream>

int main ()
{
    std::list <int> listIntegers;

    listIntegers.push_front (10);
    listIntegers.push_front (2001);
    listIntegers.push_front (-1);
    listIntegers.push_front (9999);

    std::list <int> ::iterator iElementLocator;

    for ( iElementLocator = listIntegers.begin ()
        ; iElementLocator != listIntegers.end ()
        ; ++ iElementLocator )
        std::cout << *iElementLocator << std::endl;

    return 0;
}