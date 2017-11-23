// LISTING 23.2 - Finding a Range in a Collection Using search and search_n
#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

int main ()
{
    using namespace std;

    // A sample container - vector of integers
    vector <int> vecIntegers;

    for (int nNum = -9; nNum < 10; ++ nNum)
        vecIntegers.push_back (nNum);

    // Insert some more sample values into the vector
    vecIntegers.push_back (9);
    vecIntegers.push_back (9);

    // Another sample container - a list of integers
    list <int> listIntegers;

    for (int nNum = -4; nNum < 5; ++ nNum)
        listIntegers.push_back (nNum);

    // Display the contents of the collections...
    cout << "The contents of the sample vector are: " << endl;
    vector <int>::const_iterator iVecElementLocator;
    for ( iVecElementLocator = vecIntegers.begin ()
        ; iVecElementLocator != vecIntegers.end ()
        ; ++ iVecElementLocator )
        cout << *iVecElementLocator << ' ';

    cout << endl << "The contents of the sample list are: " << endl;
    list <int>::const_iterator ilistElementLocator;
    for ( ilistElementLocator = listIntegers.begin ()
        ; ilistElementLocator != listIntegers.end ()
        ; ++ ilistElementLocator )
        cout << *ilistElementLocator << ' ';

    cout << endl << endl;
    cout << "'search' the contents of the list in the vector: " << endl;

    // Search the vector for the elements present in the list
    vector <int>::iterator iRangeLocated;
    iRangeLocated = search ( vecIntegers.begin () // Start of range
        , vecIntegers.end () // End of range to search in
        , listIntegers.begin () // Start of range to search for
        , listIntegers.end () ); // End of range to search for

    // Check if search found a match
    if (iRangeLocated != vecIntegers.end ())
    {
        cout << "The sequence in the list found a match in the vector at ";
        cout << "position: ";
        cout << distance (vecIntegers.begin (), iRangeLocated);

        cout << endl << endl;
    }

    cout << "Searching for {9, 9, 9} in the vector using 'search_n': ";
    cout << endl;

    // Now search the vector for the occurrence of pattern {9, 9, 9}
    vector <int>::iterator iPartialRangeLocated;
    iPartialRangeLocated = search_n ( vecIntegers.begin () // Start range
        , vecIntegers.end () // End range
        , 3 // Count of item to be searched for
        , 9 ); // Item to search for

    if (iPartialRangeLocated != vecIntegers.end ())
    {
        cout << "The sequence {9, 9, 9} found a match in the vector at ";
        cout << "offset-position: ";
        cout << distance (vecIntegers.begin (), iPartialRangeLocated);

        cout << endl;
    }

    return 0;
}