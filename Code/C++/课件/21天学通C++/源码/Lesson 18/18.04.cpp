// LISTING 18.4 - Using the vector::insert Function to Insert Elements at a Set Position
#include <vector>
#include <iostream>

int main ()
{
    using namespace std;

    // Instantiate a vector with 4 elements, each initialized to 90
    vector <int> vecIntegers (4, 90);

    cout << "The initial contents of the vector are: ";

    vector <int>::iterator iElement;
    for ( iElement = vecIntegers.begin ()
        ; iElement != vecIntegers.end ()
        ; ++ iElement )
    {
        cout << *iElement << ' ';
    }

    cout << endl;

    // Insert 25 at the beginning
    vecIntegers.insert (vecIntegers.begin (), 25);

    cout << "The vector after inserting an element at the beginning: ";
    for ( iElement = vecIntegers.begin ()
        ; iElement != vecIntegers.end ()
        ; ++ iElement )
    {
        cout << *iElement << ' ';
    }

    cout << endl;

    // Insert 2 numbers of value 45 at the end
    vecIntegers.insert (vecIntegers.end (), 2, 45);

    cout << "The vector after inserting two elements at the end: ";
    for ( iElement = vecIntegers.begin ()
        ; iElement != vecIntegers.end ()
        ; ++ iElement )
    {
        cout << *iElement << ' ';
    }
    cout << endl;

    // Another vector containing 2 elements of value 30
    vector <int> vecAnother (2, 30);

    // Insert two elements from another container in position [1]
    vecIntegers.insert (vecIntegers.begin () + 1,
        vecAnother.begin (), vecAnother.end ());

    cout << "The vector after inserting contents from another ";
    cout << "in the middle:" << endl;
    for ( iElement = vecIntegers.begin ()
        ; iElement != vecIntegers.end ()
        ; ++ iElement )
    {
        cout << *iElement << ' ';
    }

    return 0;
}