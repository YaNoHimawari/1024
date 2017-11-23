// LISTING 5.5 - Demonstrating the else Keyword
#include <iostream>

int main()
{
    using std::cout;
    using std::cin;

    int firstNumber, secondNumber;
    cout << "Please enter a big number: ";
    cin >> firstNumber;
    cout << "\nPlease enter a smaller number: ";
    cin >> secondNumber;
    if (firstNumber > secondNumber)
        cout << "\nThanks!\n";
    else
        cout << "\nOops. The first number is not bigger!";

    return 0;
}