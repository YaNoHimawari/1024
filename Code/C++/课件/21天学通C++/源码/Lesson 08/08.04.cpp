// LISTING 8.4 - Array Pointer Relationship
#include <iostream>
const int ARRAY_LENGTH = 5;

int main ()
{
    using namespace std;

    // An array of 5 integers initialized to 5 values
    int Numbers [ARRAY_LENGTH] = {0, 100, 200, 300, 400};

    // pInt points to the first element
    const int *pInt = Numbers;

    cout << "Using a pointer to print the contents of the array: " << endl;

    for (int nIndex = 0; nIndex < ARRAY_LENGTH; ++ nIndex)
        cout << "Element [" << nIndex << "] = " << *(pInt + nIndex) << endl;

    return 0;
}