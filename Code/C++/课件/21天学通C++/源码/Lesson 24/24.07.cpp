// LISTING 24.7 - Instantiating a Priority Queue That Holds the Smallest Value at the Top
#include <queue>
#include <iostream>

int main ()
{
    using namespace std;

    // Define a priority_queue object with greater <int> as predicate
    // So, numbers of smaller magnitudes are evaluated as greater in value
    priority_queue <int, vector <int>, greater <int> > pqIntegers;

    cout << "Inserting {10, 5, -1, 20} into the priority queue" << endl;

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
        cout << "Deleting the topmost element " << pqIntegers.top ();
        cout << endl;

        // delete the number at the 'top'
        pqIntegers.pop ();
    }

    return 0;
}