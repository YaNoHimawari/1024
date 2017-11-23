// Listing 17.4 - Using the find Member Function
#include <string>
#include <iostream>

int main ()
{
    using namespace std;

    string strSample ("Good day String! Today is beautiful!");
    cout << "The sample string is: " << endl;
    cout << strSample << endl << endl;

    // Find substring "day" in it...
    size_t nOffset = strSample.find ("day", 0);

    // Check if the substring was found...
    if (nOffset != string::npos)
        cout << "First instance of \"day\" was found at offset " << nOffset;
    else
        cout << "Substring not found." << endl;

    cout << endl << endl;

    cout << "Locating all instances of substring \"day\"" << endl;
    size_t nSubstringOffset = strSample.find ("day", 0);

    while (nSubstringOffset != string::npos)
    {
        cout << "\"day\" found at offset " << nSubstringOffset << endl;

        // Make the 'find' function search the next character onwards
        size_t nSearchOffset = nSubstringOffset + 1;

        nSubstringOffset = strSample.find ("day", nSearchOffset);
    }

    cout << endl;

    cout << "Locating all instances of character 'a'" << endl;
    const char chCharToSearch = 'a';
    size_t nCharacterOffset = strSample.find (chCharToSearch, 0);

    while (nCharacterOffset != string::npos)
    {
        cout << "'" << chCharToSearch << "' found";
        cout << " at position: " << nCharacterOffset << endl;

        // Make the 'find' function search forward from the next character
        size_t nCharSearchOffset = nCharacterOffset + 1;

        nCharacterOffset = strSample.find(chCharToSearch,nCharSearchOffset);
    }

    return 0;
}