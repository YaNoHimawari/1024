// LISTING 5.9 - A Demonstration of the Conditional Operator
#include <iostream>

int main()
{
    using namespace std;

    int x, y, z;
    cout << "Enter two numbers.\n";
    cout << "First: ";
    cin >> x;
    cout << "\nSecond: ";
    cin >> y;
    cout << "\n";

    if (x > y)
        z = x;
    else
        z = y;

    cout << "After if test, z: " << z;
    cout << "\n";

    z = (x > y) ? x : y;

    cout << "After conditional test, z: " << z;
    cout << "\n";

    return 0;
}