// Listing 17.2 - Accessing Character Elements of an STL String
#include <string>
#include <iostream>

int main ()
{
    using namespace std;

    // The sample string
    string strSTLString ("Hello String");

    // Access the contents of the string using array syntax
    cout << "Displaying characters using array-syntax: " << endl;
    for ( size_t nCharCounter = 0
        ; nCharCounter < strSTLString.length ()
        ; ++ nCharCounter )
    {
        cout << "Character [" << nCharCounter << "] is: ";
        cout << strSTLString [nCharCounter] << endl;
    }
    cout << endl;

    // Access the contents of a string using iterators
    cout << "Displaying characters using iterators: " << endl;
    int nCharOffset = 0;
    string::const_iterator iCharacterLocator;
    for ( iCharacterLocator = strSTLString.begin ()
        ; iCharacterLocator != strSTLString.end ()
        ; ++ iCharacterLocator )
    {
        cout << "Character [" << nCharOffset ++ << "] is: ";
        cout << *iCharacterLocator << endl;
    }
    cout << endl;

    // Access the contents of a string as a C-style string
    cout << "The char* representation of the string is: ";
    cout << strSTLString.c_str () << endl;

    return 0;
}