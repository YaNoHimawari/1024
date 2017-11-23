// LISTING 18.7 - Using pop_back to Erase the Last Element
#include <iostream>
#include <vector>

int main ()
{
    using namespace std;

    vector <int> vecDynamicIntegerArray;

    // Insert sample integers into the vector:
    vecDynamicIntegerArray.push_back (50);
    vecDynamicIntegerArray.push_back (1);
    vecDynamicIntegerArray.push_back (987);
    vecDynamicIntegerArray.push_back (1001);

    cout << "The vector contains ";
    cout << vecDynamicIntegerArray.size ();
    cout << " elements before calling pop_back" << endl;

    // Erase one element at the end
    vecDynamicIntegerArray.pop_back ();

    cout << "The vector contains ";
    cout << vecDynamicIntegerArray.size ();
    cout << " elements after calling pop_back" << endl;

    cout << "Enumerating items in the vector... " << endl;

    unsigned int nElementIndex = 0;
    while (nElementIndex < vecDynamicIntegerArray.size ())
    {
        cout << "Element at position " << nElementIndex << " is: ";
        cout << vecDynamicIntegerArray [nElementIndex] << endl;
        // move to the next element
        ++ nElementIndex;
    }

    return 0;
}