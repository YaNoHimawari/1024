// LISTING 22.4 - Using the Unary Predicate IsMultiple (from 22.03)
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// Insert definition of struct IsMultiple from Listing 22.3 here

int main ()
{
    vector <int> vecIntegers;

    cout << "The vector contains the following sample values: ";

    // Insert sample values: 25 - 31
    for (int nCount = 25; nCount < 32; ++ nCount)
    {
        vecIntegers.push_back (nCount);
        cout << nCount << ' ';
    }

    cout << endl;

    // Find the first element that is a multiple of 4 in the collection
    vector <int>::iterator iElement;
    iElement = find_if ( vecIntegers.begin ()
        , vecIntegers.end ()
        , IsMultiple <int> (4) ); // Unary predicate initialized to 4

    if (iElement != vecIntegers.end ())
    {
        cout << "The first element in the vector divisible by 4 is: ";
        cout << *iElement << endl;
    }

    return 0;
}