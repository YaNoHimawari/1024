// LISTING 23.1 - Sample That Demonstrates the Usage of std::count, count_if, find, find_if on a Sample Collection
#include <algorithm>
#include <vector>
#include <iostream>

// A unary predicate for the *_if functions
template <typename elementType>
bool IsEven (const elementType& number)
{
    // return true if the number is even
    return ((number % 2) == 0);
}

int main ()
{
    using namespace std;

    // A sample container - vector of integers
    vector <int> vecIntegers;

    // Inserting sample values
    for (int nNum = -9; nNum < 10; ++ nNum)
        vecIntegers.push_back (nNum);

    // Display all elements in the collection
    cout << "Elements in our sample collection are: " << endl;
    vector <int>::const_iterator iElementLocator;
    for ( iElementLocator = vecIntegers.begin ()
        ; iElementLocator != vecIntegers.end ()
        ; ++ iElementLocator )
        cout << *iElementLocator << ' ';

    cout << endl << endl;

    // Determine the total number of elements
    cout << "The collection contains '";
    cout << vecIntegers.size () << "' elements" << endl;

    // Use the count_if algorithm with the unary predicate IsEven:
    size_t nNumEvenElements = count_if (vecIntegers.begin (),
        vecIntegers.end (), IsEven <int> );

    cout << "Number of even elements: " << nNumEvenElements << endl;
    cout << "Number of odd elements: ";
    cout << vecIntegers.size () - nNumEvenElements << endl;

    // Use count to determine the number of '0's in the vector
    size_t nNumZeroes = count (vecIntegers.begin (),vecIntegers.end (),0);
    cout << "Number of instances of '0': " << nNumZeroes << endl << endl;

    cout << "Searching for an element of value 3 using find: " << endl;

    // Find a sample integer '3' in the vector using the 'find' algorithm
    vector <int>::iterator iElementFound;
    iElementFound = find ( vecIntegers.begin () // Start of range
        , vecIntegers.end () // End of range
        , 3 ); // Element to find

    // Check if find succeeded
    if ( iElementFound != vecIntegers.end ())
        cout << "Result: Element found!" << endl << endl;
    else
        cout << "Result: Element was not found in the collection." << endl;

    cout << "Finding the first even number using find_if: " << endl;

    // Find the first even number in the collection
    vector <int>::iterator iEvenNumber;
    iEvenNumber = find_if ( vecIntegers.begin ()// Start of range
        , vecIntegers.end () // End of range
        , IsEven <int> ); // Unary Predicate

    if (iEvenNumber != vecIntegers.end ())
    {
        cout << "Number '" << *iEvenNumber << "' found at position [";
        cout << distance (vecIntegers.begin (), iEvenNumber);
        cout << "]" << endl;
    }

    return 0;
}