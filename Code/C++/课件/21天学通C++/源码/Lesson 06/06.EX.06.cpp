#include <iostream>
using namespace std;
short int Divider(
                  unsigned short int valone,
                  unsigned short int valtwo);
int main()
{
    unsigned short int one, two;
    short int answer;
    cout << "Enter two numbers.\n Number one: ";
    cin >> one;
    cout << "Number two: ";
    cin >> two;
    answer = Divider(one, two);
    if (answer > -1)
        cout << "Answer: " << answer;
    else
        cout << "Error, can't divide by zero!";
    return 0;
}
short int Divider(unsigned short int valOne, unsigned short int valTwo)
{
    if (valTwo == 0)
        return -1;
    else
        return valOne / valTwo;
}