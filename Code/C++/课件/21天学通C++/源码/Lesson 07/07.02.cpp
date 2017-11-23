// LISTING 7.2 - while Loops
#include <iostream>

int main()
{
    using namespace std;
    int counter = 0; // initialize the condition

    while(counter < 5) // test condition still true
    {
        counter++; // body of the loop
        cout << "counter: " << counter << endl;
    }

    cout << "Complete. Counter: " << counter << endl;
    return 0;
}