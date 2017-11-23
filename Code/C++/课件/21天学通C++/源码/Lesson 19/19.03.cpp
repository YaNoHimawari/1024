// LISTING 19.3 - Inserting Elements in the List Using push_back
#include <list>
#include <iostream>

int main ()
{
    std::list <int> listIntegers;

    listIntegers.push_back (10);
    listIntegers.push_back (2001);
    listIntegers.push_back (-1);
    listIntegers.push_back (9999);

    std::list <int> ::iterator iElementLocator;

    for ( iElementLocator = listIntegers.begin ()
        ; iElementLocator != listIntegers.end ()
        ; ++ iElementLocator )
        std::cout << *iElementLocator << std::endl;

    return 0;
}