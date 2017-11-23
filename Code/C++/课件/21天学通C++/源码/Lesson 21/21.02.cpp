// LISTING 21.2 - Inserting Elements in an STL Map and Multimap
#include <map>
#include <iostream>

using namespace std;

// Type-define the map and multimap definition for easy readability
typedef map <int, string> MAP_INT_STRING;
typedef multimap <int, string> MMAP_INT_STRING;

int main ()
{
    MAP_INT_STRING mapIntToString;

    // Insert key-value pairs into the map using value_type
    mapIntToString.insert (MAP_INT_STRING::value_type (3, "Three"));

    // Insert a pair using function make_pair
    mapIntToString.insert (make_pair (-1, "Minus One"));

    // Insert a pair object directly
    mapIntToString.insert (pair <int, string> (1000, "One Thousand"));

    // Insert using an array-like syntax for inserting key-value pairs
    mapIntToString [1000000] = "One Million";

    cout << "The map contains " << mapIntToString.size ();
    cout << " key-value pairs. " << endl;
    cout << "The elements in the map are: " << endl;

    // Print the contents of the map to the screen
    MAP_INT_STRING::const_iterator iMapPairLocator;

    for ( iMapPairLocator = mapIntToString.begin ()
        ; iMapPairLocator != mapIntToString.end ()
        ; ++ iMapPairLocator )
    {
        cout << "Key: " << iMapPairLocator->first;
        cout << " Value: " << iMapPairLocator->second.c_str ();

        cout << endl;
    }

    MMAP_INT_STRING mmapIntToString;

    // The insert function works the same way for multimap too
    mmapIntToString.insert (MMAP_INT_STRING::value_type (3, "Three"));
    mmapIntToString.insert (MMAP_INT_STRING::value_type (45, "Forty Five"));
    mmapIntToString.insert (make_pair (-1, "Minus One"));
    mmapIntToString.insert (pair <int, string> (1000, "One Thousand"));

    // A multimap can store duplicates - insert one
    mmapIntToString.insert (MMAP_INT_STRING::value_type (1000, "Thousand"));

    cout << endl << "The multimap contains " << mmapIntToString.size ();
    cout << " key-value pairs." << endl;
    cout << "The elements in the multimap are: " << endl;

    // Print the contents of the map to the screen
    MMAP_INT_STRING::const_iterator iMultiMapPairLocator;

    for ( iMultiMapPairLocator = mmapIntToString.begin ()
        ; iMultiMapPairLocator != mmapIntToString.end ()
        ; ++ iMultiMapPairLocator )
    {
        cout << "Key: " << iMultiMapPairLocator->first;
        cout << " Value: " << iMultiMapPairLocator->second.c_str ();

        cout << endl;
    }

    cout << endl;

    // The multimap can also return the number of pairs with the same key
    cout << "The number of pairs in the multimap with 1000 as their key: "
        << mmapIntToString.count (1000) << endl;

    return 0;
}