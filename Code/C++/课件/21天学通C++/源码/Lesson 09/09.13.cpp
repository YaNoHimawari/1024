// LISTING 9.13 - Memory Leaks
#include <iostream>

int& GetInt ();

int main()
{
    int & rInt = GetInt ();
    std::cout << "rInt = " << rInt << std::endl;

    return 0;
}

int & GetInt ()
{
    // Instantiate an integer object on the free store / heap
    int* pInteger = new int (25);

    return *pInteger;
}