// LISTING 23.11 - Using lower_bound and upper_bound to Insert in a Sorted Collection
#include <algorithm>
#include <list>
#include <string>
#include <iostream>

int main ()
{
    using namespace std;

    typedef list <string> LIST_STRINGS;

    // A sample list of strings
    LIST_STRINGS listNames;

    // Insert sample values
    listNames.push_back ("John Doe");
    listNames.push_back ("Brad Pitt");
    listNames.push_back ("Jack Nicholson");
    listNames.push_back ("Sean Penn");
    listNames.push_back ("Anna Hoover");

    // Sort all the names in the list
    listNames.sort ();

    cout << "The sorted contents of the list are: " << endl;
    LIST_STRINGS::iterator iNameLocator;
    for ( iNameLocator = listNames.begin ()
        ; iNameLocator != listNames.end ()
        ; ++ iNameLocator )
    {
        cout << "Name [" << distance (listNames.begin (), iNameLocator);
        cout << "] = \"" << *iNameLocator << "\"" << endl;
    }

    cout << endl;

    LIST_STRINGS::iterator iMinInsertPosition;

    // The closest / lowest position where the element can be inserted
    iMinInsertPosition = lower_bound ( listNames.begin (), listNames.end ()
        , "Brad Pitt" );

    LIST_STRINGS::iterator iMaxInsertPosition;

    // The farthest / highest position where an element may be inserted
    iMaxInsertPosition = upper_bound ( listNames.begin (), listNames.end ()
        , "Brad Pitt" );

    cout << "The lowest index where \"Brad Pitt\" can be inserted is: ";
    cout << distance (listNames.begin (), iMinInsertPosition) << endl;

    cout << "The highest index where \"Brad Pitt\" can be inserted is: ";
    cout << distance (listNames.begin (), iMaxInsertPosition) << endl;

    cout << endl;

    cout << "Inserting \"Brad Pitt\" in the sorted list:" << endl;
    listNames.insert (iMinInsertPosition, "Brad Pitt");

    cout << "The contents of the list now are: " << endl;
    for ( iNameLocator = listNames.begin ()
        ; iNameLocator != listNames.end ()
        ; ++ iNameLocator )
    {
        cout << "Name [" << distance (listNames.begin (), iNameLocator);
        cout << "] = \"" << *iNameLocator << "\"" << endl;
    }

    return 0;
}