// LISTING 20.4 - Using the erase Member Function on a Multiset
#include <set>
#include <iostream>

using namespace std;
typedef multiset <int> MSETINT;

int main ()
{
    MSETINT msetIntegers;

    // Insert some random values
    msetIntegers.insert (43);
    msetIntegers.insert (78);
    msetIntegers.insert (78); // Duplicate
    msetIntegers.insert (-1);
    msetIntegers.insert (124);

    MSETINT::const_iterator iElement;

    cout << "multiset contains " << msetIntegers.size () << " elements.";
    cout << " These are: " << endl;

    // Write contents of the multiset to the screen
    for ( iElement = msetIntegers.begin ()
        ; iElement != msetIntegers.end ()
        ; ++ iElement )
        cout << *iElement << endl;

    cout << "Please enter a number to be erased from the set" << endl;
    int nNumberToErase = 0;
    cin >> nNumberToErase;

    cout << "Erasing " << msetIntegers.count (nNumberToErase);
    cout << " instances of value " << nNumberToErase << endl;

    // Try finding an element
    msetIntegers.erase (nNumberToErase);

    cout << "multiset contains " << msetIntegers.size () << " elements.";
    cout << " These are: " << endl;
    for ( iElement = msetIntegers.begin ()
        ; iElement != msetIntegers.end ()
        ; ++ iElement )
        cout << *iElement << endl;

    return 0;
}