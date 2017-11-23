// LISTING 24.4 - Working with a Queue of Integers
#include <queue>
#include <iostream>

int main ()
{
    using namespace std;

    // A queue of integers
    queue <int> qIntegers;

    cout << "Inserting {10, 5, -1, 20} into the queue" << endl;

    // elements pushed into the queue are inserted at the end
    qIntegers.push (10);
    qIntegers.push (5);
    qIntegers.push (-1);
    qIntegers.push (20);
    // the elements in the queue now are {20, -1, 5, 10} in that order

    cout << "The queue contains " << qIntegers.size ();
    cout << " elements" << endl;
    cout << "Element at the front: " << qIntegers.front() << endl;
    cout << "Element at the back: " << qIntegers.back ();
    cout << endl << endl;

    cout << "Removing them one after another..." << endl;
    while (qIntegers.size () != 0)
    {
        cout << "Deleting element " << qIntegers.front () << endl;

        // Remove the element at the front of the queue
        qIntegers.pop ();
    }

    cout << endl;

    // Test if the queue is empty
    if (qIntegers.empty ())
        cout << "The queue is now empty!";

    return 0;
}