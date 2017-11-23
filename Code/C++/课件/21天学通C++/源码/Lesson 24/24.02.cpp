// LISTING 24.2 - Working with a Stack of Integers
#include <stack>
#include <iostream>

int main ()
{
    using namespace std;

    // A stack of integers
    stack <int> stackIntegers;

    // Push sample values to the top of the stack
    cout << "Pushing numbers {25, 10, -1, 5} into the stack:" << endl;

    // push = insert at top of the container
    stackIntegers.push (25);
    stackIntegers.push (10);
    stackIntegers.push (-1);
    stackIntegers.push (5);
    // So, 25 is at the bottom and 5 is at the top!

    cout << "The stack contains " << stackIntegers.size () << " elements";
    cout << endl;

    // pop = remove the topmost element
    cout << endl << "Popping them one after another..." << endl;

    while (stackIntegers.size () != 0)
    {
        cout << "The element at the top is: " << stackIntegers.top();
        cout << endl << "Removing it from the stack!" << endl;

        // Remove the topmost element
        stackIntegers.pop ();
    }

    if (stackIntegers.empty ())
        cout << endl << "The stack is now empty!";

    return 0;
}