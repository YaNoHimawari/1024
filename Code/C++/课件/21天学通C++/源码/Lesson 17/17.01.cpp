// Listing 17.1 - STL String Instantiation and Copy Techniques
#include <string>
#include <iostream>

int main ()
{
    using namespace std;
    const char* pszConstString = "Hello String!";
    cout << "Constant string is: " << pszConstString << endl;

    std::string strFromConst (pszConstString);
    cout << "strFromConst is: " << strFromConst << endl;

    std::string str2 ("Hello String!");
    std::string str2Copy (str2);
    cout << "str2Copy is: " << str2Copy << endl;

    // Initialize a string to the first 5 characters of another
    std::string strPartialCopy (pszConstString, 5);
    cout << "strPartialCopy is: " << strPartialCopy << endl;

    // Initialize a string object to contain 10 'a's
    std::string strRepeatChars (10, 'a');
    cout << "strRepeatChars is: " << strRepeatChars << endl;

    return 0;
}