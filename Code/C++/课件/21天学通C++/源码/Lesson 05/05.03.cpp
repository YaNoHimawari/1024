// LISTING 5.3 - A Demonstration of Prefix and Postfix Operators
#include <iostream>

int main()
{
    using std::cout;

    int myAge = 39; // initialize two integers
    int yourAge = 39;
    cout << "I am: " << myAge << " years old.\n";
    cout << "You are: " << yourAge << " years old\n";

    myAge++; // postfix increment
    ++yourAge; // prefix increment

    cout << "One year passes...\n";
    cout << "I am: " << myAge << " years old.\n";
    cout << "You are: " << yourAge << " years old\n";
    cout << "Another year passes\n";
    cout << "I am: " << myAge++ << " years old.\n";
    cout << "You are: " << ++yourAge << " years old\n";
    cout << "Let's print it again.\n";
    cout << "I am: " << myAge << " years old.\n";
    cout << "You are: " << yourAge << " years old\n";

    return 0;
}