// LISTING 7.1 - Looping with the Keyword goto
#include <iostream>

int main()
{
    using namespace std;
    int counter = 0; // initialize counter

loop:
    counter ++; // top of the loop
    cout << "counter: " << counter << endl;
    if (counter < 5) // test the value
        goto loop; // jump to the top

    cout << "Complete. Counter: " << counter << endl;

    return 0;
}