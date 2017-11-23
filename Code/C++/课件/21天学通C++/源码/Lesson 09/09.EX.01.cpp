//Exercise 9.1 -
#include <iostream>
int main()
{
    int varOne = 1; // sets varOne to 1
    int& rVar = varOne;
    int* pVar = &varOne;
    rVar = 5; // sets varOne to 5
    *pVar = 7; // sets varOne to 7
    // All three of the following will print 7:
    std::cout << "variable: " << varOne << std::endl;
    std::cout << "reference: " << rVar << std::endl;
    std::cout << "pointer: " << *pVar << std::endl;
    return 0;
}