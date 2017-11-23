// LISTING 3.4 - A Demonstration of Putting Too Large a Value in an unsigned short Integer
#include <iostream>

int main()
{
    using std::cout;
    using std::endl;

    unsigned short int smallNumber;
    smallNumber = 65535;
    cout << "small number:" << smallNumber << endl;
    smallNumber++;
    cout << "small number:" << smallNumber << endl;
    smallNumber++;
    cout << "small number:" << smallNumber << endl;

    return 0;
}