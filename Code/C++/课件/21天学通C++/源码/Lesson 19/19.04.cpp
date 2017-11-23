// LISTING 19.4 - The Various Methods of Inserting Elements in a List
#include <list>
#include <iostream>

using namespace std;

void PrintListContents (const list <int>& listInput);

int main ()
{
    list <int> listIntegers1;

    // Inserting elements at the beginning...
    listIntegers1.insert (listIntegers1.begin (), 4);
    listIntegers1.insert (listIntegers1.begin (), 3);
    listIntegers1.insert (listIntegers1.begin (), 2);
    listIntegers1.insert (listIntegers1.begin (), 1);

    // Inserting an element at the end...
    listIntegers1.insert (listIntegers1.end (), 5);

    cout << "The contents of list 1 after inserting elements:" << endl;
    PrintListContents (listIntegers1);

    list <int> listIntegers2;

    // Inserting 4 elements of the same value 0...
    listIntegers2.insert (listIntegers2.begin (), 4, 0);

    cout << "The contents of list 2 after inserting '";
    cout << listIntegers2.size () << "' elements of a value:" << endl;
    PrintListContents (listIntegers2);

    list <int> listIntegers3;

    // Inserting elements from another list at the beginning...
    listIntegers3.insert (listIntegers3.begin (),
        listIntegers1.begin (), listIntegers1.end ());

    cout << "The contents of list 3 after inserting the contents of ";
    cout << "list 1 at the beginning:" << endl;
    PrintListContents (listIntegers3);

    // Inserting elements from another list at the end...
    listIntegers3.insert (listIntegers3.end (),
        listIntegers2.begin (), listIntegers2.end ());

    cout << "The contents of list 3 after inserting ";
    cout << "the contents of list 2 at the beginning:" << endl;
    PrintListContents (listIntegers3);

    return 0;
}

void PrintListContents (const list <int>& listInput)
{
    // Write values to the screen...
    cout << "{ ";

    std::list <int>::const_iterator iElementLocator;
    for ( iElementLocator = listInput.begin ()
        ; iElementLocator != listInput.end ()
        ; ++ iElementLocator )
        cout << *iElementLocator << " ";

    cout << "}" << endl << endl;
}