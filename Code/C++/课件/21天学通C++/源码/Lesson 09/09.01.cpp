// LISTING 9.1 - Creating and Using References
#include <iostream>

int main()
{
    using namespace std;
    int intOne;
    int &rSomeRef = intOne;

    intOne = 5;
    cout << "intOne: " << intOne << endl;
    cout << "rSomeRef: " << rSomeRef << endl;

    rSomeRef = 7;
    cout << "intOne: " << intOne << endl;
    cout << "rSomeRef: " << rSomeRef << endl;

    return 0;
}