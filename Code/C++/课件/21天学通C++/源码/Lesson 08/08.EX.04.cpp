#include <iostream>
int main()
{
    int theInteger;
    int *pInteger = &theInteger;
    *pInteger = 5;
    std::cout << "The Integer: "
        << *pInteger << std::endl;
    return 0;
}