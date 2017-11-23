// LISTING 23.7 - A Sample That Demonstrates copy, copy_backward, remove, and remove_if
#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

// A unary predicate for the remove_if function
template <typename elementType>
bool IsOdd (const elementType& number)
{
    // returns true if the number is odd
    return ((number % 2) == 1);
}

int main ()
{
    using namespace std;

    // A list with sample values
    list <int> listIntegers;

    for (int nCount = 0; nCount < 10; ++ nCount)
        listIntegers.push_back (nCount);

    cout << "Elements in the source (list) are: " << endl;

    // Display all elements in the collection
    list <int>::const_iterator iElementLocator;
    for ( iElementLocator = listIntegers.begin ()
        ; iElementLocator != listIntegers.end ()
        ; ++ iElementLocator )
        cout << *iElementLocator << ' ';

    cout << endl << endl;

    // Initialize the vector to hold twice as many elements as the list
    vector <int> vecIntegers (listIntegers.size () * 2);

    vector <int>::iterator iLastPos;
    iLastPos = copy ( listIntegers.begin () // start of source range
        , listIntegers.end () // end of source range
        , vecIntegers.begin () );// start of destination range

    // Now, use copy_backward to copy the same list into the vector
    copy_backward ( listIntegers.begin ()
        , listIntegers.end ()
        , vecIntegers.end () );

    cout << "Elements in the destination (vector) after copy: " << endl;

    // Display all elements in the collection
    vector <int>::const_iterator iDestElementLocator;
    for ( iDestElementLocator = vecIntegers.begin ()
        ; iDestElementLocator != vecIntegers.end ()
        ; ++ iDestElementLocator )
        cout << *iDestElementLocator << ' ';

    cout << endl << endl;

    /*
    Remove all instances of '0':
    std::remove does not change the size of the container,
    it simply moves elements forward to fill gaps created
    and returns the new 'end' position.
    */
    vector <int>::iterator iNewEnd;
    iNewEnd = remove (vecIntegers.begin (), vecIntegers.end (), 0);

    // Use this new 'end position' to resize vector
    vecIntegers.erase (iNewEnd, vecIntegers.end ());

    // Remove all odd numbers from the vector using remove_if
    iNewEnd = remove_if (vecIntegers.begin (), vecIntegers.end (),
        IsOdd <int>); // The predicate

    vecIntegers.erase (iNewEnd , vecIntegers.end ());

    cout << "Elements in the destination (vector) after remove: " << endl;

    // Display all elements in the collection
    for ( iDestElementLocator = vecIntegers.begin ()
        ; iDestElementLocator != vecIntegers.end ()
        ; ++ iDestElementLocator )
        cout << *iDestElementLocator << ' ';

    return 0;
}