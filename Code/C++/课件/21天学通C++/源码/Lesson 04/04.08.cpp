// LISTING 4.8 - Using strncpy()

#include <iostream>
#include <string.h>

int main()
{
    const int MaxLength = 80;
    char String1[] = "No man is an island";
    char String2[MaxLength+1] = {'\0'};

    strncpy(String2, String1, MaxLength); // safer than strcpy

    std::cout << "String1: " << String1 << std::endl;
    std::cout << "String2: " << String2 << std::endl;

    return 0;
}