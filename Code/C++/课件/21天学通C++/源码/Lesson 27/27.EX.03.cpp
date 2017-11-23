#include <iostream>
using namespace std;

int main()
{
    char ch;
    cout << "enter a phrase: ";
    while ( cin.get(ch) )
    {
        switch (ch)
        {
        case '!':
            cout << '$';
            break;
        case '#':
            break;
        default:
            cout << ch;
            break;
        }
    }
    return 0;
}