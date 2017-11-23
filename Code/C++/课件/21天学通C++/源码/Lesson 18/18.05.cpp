// LISTING 18.5 - Accessing Elements in a Vector Using Array Semantics
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

    unsigned int nElementIndex = 0;
    while (nElementIndex < vecDynamicIntegerArray.size ())
    {
        cout << "Element at position " << nElementIndex;
        cout << " is: " << vecDynamicIntegerArray [nElementIndex] << endl;

        ++ nElementIndex;
    }

    return 0;
}