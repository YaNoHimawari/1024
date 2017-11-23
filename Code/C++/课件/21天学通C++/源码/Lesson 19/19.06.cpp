// LISTING 19.6 - Reversing Elements in a List
#include <list>
#include <iostream>

using namespace std;

void PrintListContents (const list <int>& listInput);

int main ()
{
    std::list <int> listIntegers;

    // Insert elements at the beginning...
    listIntegers.push_front (4);
    listIntegers.push_front (3);
    listIntegers.push_front (2);

    listIntegers.push_front (1);
    listIntegers.push_front (0);

    // Insert an element at the end...
    listIntegers.push_back (5);

    cout << "Initial contents of the list:" << endl;
    PrintListContents (listIntegers);

    listIntegers.reverse ();

    cout << "Contents of the list after using reverse ():" << endl;
    PrintListContents (listIntegers);

    return 0;
}

void PrintListContents (const list <int>& listInput)
{
    if (listInput.size () > 0)
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
    else
        cout << "List is empty!" << endl;
}