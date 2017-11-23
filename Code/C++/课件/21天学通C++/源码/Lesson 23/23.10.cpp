// LISTING 23.10 - Using partition and stable_partition to Partition a Range of Integers into Even and Odd Values
#include <algorithm>
#include <vector>
#include <iostream>

bool IsEven (const int& nNumber)
{
    return ((nNumber % 2) == 0);
}

int main ()
{
    using namespace std;

    // a sample collection...
    vector <int> vecIntegers;

    // fill sample values 0 - 9, in that order
    for (int nNum = 0; nNum < 10; ++ nNum)
        vecIntegers.push_back (nNum);

    // a copy of the sample vector
    vector <int> vecCopy (vecIntegers);

    // separate even values from the odd ones - even comes first.
    partition (vecIntegers.begin (), vecIntegers.end (), IsEven);

    // display contents
    cout << "The contents of the vector after using 'partition' are:";
    cout << endl << "{";

    for (size_t nItem = 0; nItem < vecIntegers.size (); ++ nItem)
        cout << vecIntegers [nItem] << ' ';

    cout << "}" << endl << endl;

    // now use stable_partition on the vecCopy - maintains relative order
    stable_partition (vecCopy.begin (), vecCopy.end (), IsEven);

    // display contents of vecCopy
    cout << "The effect of using 'stable_partition' is: " << endl << "{";

    for (size_t nItem = 0; nItem < vecCopy.size (); ++ nItem)
        cout << vecCopy [nItem] << ' ';

    cout << "}" << endl << endl;

    return 0;
}