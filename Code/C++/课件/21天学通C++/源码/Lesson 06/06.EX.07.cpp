#include <iostream>
using namespace std;
typedef unsigned short USHORT;
typedef unsigned long ULONG;
ULONG GetPower(USHORT n, USHORT power);
Lesson 6, "Organizing Code with Functions" 785
D
40_0672329417_appd.qxd 6/6/08 9:46 AM Page 785
int main()
{
    USHORT number, power;
    ULONG answer;
    cout << "Enter a number: ";
    cin >> number;
    cout << "To what power? ";
    cin >> power;
    answer = GetPower(number,power);
    cout << number << " to the " << power << "th power is " <<
        answer << endl;
    return 0;
}
ULONG GetPower(USHORT n, USHORT power)
{
    if(power == 1)
        return n;
    else
        return (n * GetPower(n,power-1));
}