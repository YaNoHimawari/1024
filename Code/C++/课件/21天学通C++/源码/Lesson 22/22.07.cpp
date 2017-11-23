// LISTING 22.7 Using a Binary Predicate in a std::set to Store a Set of Names
#include <set>
#include <iostream>

// Insert CCompareStringNoCase from listing 22.6 here

int main ()
{
    typedef set <string, CCompareStringNoCase> SET_NAMES;

    // Define a set of string to hold names
    SET_NAMES setNames;

    // Insert some sample names in to the set
    setNames.insert ("Tina");
    setNames.insert ("jim");
    setNames.insert ("Jack");
    setNames.insert ("Sam");

    cout << "The sample names in the set are: " << endl;

    // Display the names in the set
    SET_NAMES::const_iterator iNameLocator;
    for ( iNameLocator = setNames.begin ()
        ; iNameLocator != setNames.end ()
        ; ++ iNameLocator )
        cout << *iNameLocator << endl;

    cout << "Enter a name you wish to search the set for: ";
    string strUserInput;
    cin >> strUserInput;

    SET_NAMES::iterator iNameFound = setNames.find (strUserInput);

    if (iNameFound != setNames.end ())
        cout << "'" << *iNameFound << "' was found in the set" << endl;
    else
        cout << "Name '" << strUserInput << "' was not found in the set";

    return 0;
}