#include <vector>
#include <list>
#include <iostream>
using namespace std;
int main ()
{
    vector <int> vecData (4);
    vecData [0] = 0;
    vecData [1] = 10;
    vecData [2] = 20;
    vecData [3] = 30;
    list <int> listIntegers;
    // Insert the contents of the vector into the beginning of the list
    listIntegers.insert (listIntegers.begin (),
        vecData.begin (), vecData.end());
    cout << "The contents of the list are: ";
    list <int>::const_iterator iElement;
    for ( iElement = listIntegers.begin ()
        ; iElement != listIntegers.end ()
        ; ++ iElement)
        cout << *iElement << " ";
    return 0;
};