// LISTING 19.7 - Sorting a List of Integers in Ascending and Descending Order
#include <list>
#include <iostream>

using namespace std;

void PrintListContents (const list <int>& listInput);
bool SortPredicate_Descending (const int& lsh, const int& rsh);

int main ()
{
    std::list <int> listIntegers;

    // Insert elements at the beginning...
    listIntegers.push_front (444);
    listIntegers.push_front (300);
    listIntegers.push_front (21111);

    listIntegers.push_front (-1);
    listIntegers.push_front (0);

    // Insert an element at the end...
    listIntegers.push_back (-5);

    cout << "Initial contents of the list are - " << endl;
    PrintListContents (listIntegers);

    listIntegers.sort ();

    cout << "Order of elements after sort():" << endl;
    PrintListContents (listIntegers);

    listIntegers.sort (SortPredicate_Descending);
    cout << "Order of elements after sort() with a predicate:" << endl;

    PrintListContents (listIntegers);

    return 0;
}

void PrintListContents (const list <int>& listInput)
{
    if (listInput.size () > 0)
    {
        // Write the output...
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

bool SortPredicate_Descending (const int& lsh, const int& rsh)
{
    return (rsh < lsh);
}