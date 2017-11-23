// LISTING 23.8 - Using replace and replace_if to Replace Values in a Specified Range
#include <iostream>
#include <algorithm>
#include <vector>

// The unary predicate used by replace_if to replace even numbers
bool IsEven (const int & nNum)
{
    return ((nNum % 2) == 0);
}

int main ()
{
    using namespace std;

    // Initialize a sample vector with 6 elements
    vector <int> vecIntegers (6);

    // fill first 3 elements with value 8
    fill (vecIntegers.begin (), vecIntegers.begin () + 3, 8);

    // fill last 3 elements with value 5
    fill_n (vecIntegers.begin () + 3, 3, 5);

    // shuffle the container
    random_shuffle (vecIntegers.begin (), vecIntegers.end ());

    cout << "The initial contents of the vector are: " << endl;
    for (size_t nIndex = 0; nIndex < vecIntegers.size (); ++ nIndex)
    {
        cout << "Element [" << nIndex << "] = ";
        cout << vecIntegers [nIndex] << endl;
    }

    cout << endl << "Using 'std::replace' to replace value 5 by 8" << endl;
    replace (vecIntegers.begin (), vecIntegers.end (), 5, 8);

    cout << "Using 'std::replace_if' to replace even values by -1" << endl;
    replace_if (vecIntegers.begin (), vecIntegers.end (), IsEven, -1);

    cout << endl << "Contents of the vector after replacements:" << endl;
    for (size_t nIndex = 0; nIndex < vecIntegers.size (); ++ nIndex)
    {
        cout << "Element [" << nIndex << "] = ";
        cout << vecIntegers [nIndex] << endl;
    }

    return 0;
}