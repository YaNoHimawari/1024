// LISTING 4.9 Initializing, Assigning (Copying), and Concatenating Strings Using std::string
#include <string>
#include <iostream>

int main ()
{
    // A sample string
    std::string str1 ("This is a C++ string! ");

    // display on the console / screen
    std::cout << "str1 = " << str1 << std::endl;

    // a second sample string
    std::string str2;

    // assign to make a copy of the first in the second
    str2 = str1;

    // display the copy
    std::cout << "Result of assignment, str2 = " << str2 << std::endl;

    // change (overwrite) the second string with a new value
    str2 = "Hello string!";

    std::cout << "After over-writing contents, str2 = " << str2;
    std::cout << std::endl << std::endl;

    std::string strAddResult;

    // Add the two std::strings (concatenate) and store in a third
    strAddResult = str1 + str2;

    std::cout << "The result of str1 + str2 is = " << strAddResult;

    return 0;
}