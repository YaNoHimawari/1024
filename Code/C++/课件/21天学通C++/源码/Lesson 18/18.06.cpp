// LISTING 18.6 Accessing Elements in a Vector Using Pointer Semantics (Iterators)
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

    // Access objects in a vector using iterators:
    vector<int>::iterator iElementLocator = vecDynamicIntegerArray.begin();

    while (iElementLocator != vecDynamicIntegerArray.end ())
    {
        size_t nElementIndex = distance (vecDynamicIntegerArray.begin (),
            iElementLocator);

        cout << "Element at position ";
        cout << nElementIndex << " is: " << *iElementLocator << endl;

        // move to the next element
        ++ iElementLocator;
    }

    return 0;
}