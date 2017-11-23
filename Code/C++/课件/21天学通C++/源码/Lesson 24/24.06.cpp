// LISTING 24.6 - Working with a priority_queue
#include <queue>
#include <iostream>

int main ()
{
    using namespace std;

    priority_queue <int> pqIntegers;
    cout << "Inserting {10, 5, -1, 20} into the priority_queue" << endl;

    // elements get push-ed into the p-queue
    pqIntegers.push (10);
    pqIntegers.push (5);
    pqIntegers.push (-1);
    pqIntegers.push (20);

    cout << "The queue contains " << pqIntegers.size () << " elements";
    cout << endl;
    cout << "Element at the top: " << pqIntegers.top () << endl << endl;

    while (!pqIntegers.empty ())
    {
        cout << "Deleting the topmost element: " << pqIntegers.top ();
        cout << endl;

        pqIntegers.pop ();
    }

    return 0;
}