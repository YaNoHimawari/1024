#include <list>
#include <string>
#include <iostream>
using namespace std;

int main ()
{
    list <string> listNames;
    listNames.push_back ("Jack");
    listNames.push_back ("John");
    listNames.push_back ("Anna");
    listNames.push_back ("Skate");
    cout << "The contents of the list are: ";
    list <string>::const_iterator iElement;
    for (iElement = listNames.begin(); iElement!=listNames.end();
        ++iElement)
        cout << *iElement << " ";
    cout << endl;
    cout << "The contents after reversing are: ";
    listNames.reverse ();
    for (iElement = listNames.begin(); iElement!=listNames.end();
        ++iElement)
        cout << *iElement << " ";
    cout << endl;
    cout << "The contents after sorting are: ";
    listNames.sort ();
    for (iElement = listNames.begin(); iElement!=listNames.end();
        ++iElement)
        cout << *iElement << " ";
    cout << endl;
    return 0;
};