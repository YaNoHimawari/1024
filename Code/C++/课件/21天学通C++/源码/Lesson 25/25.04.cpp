// LISTING 25.4 - Using the vector<bool>
#include <vector>
#include <iostream>

int main ()
{
    using namespace std;

    // Instantiate a vector<bool> to hold 3 elements
    vector <bool> vecBool (3);

    // Assign 3 elements using the array operator []
    vecBool [0] = true;
    vecBool [1] = true;
    vecBool [2] = false;

    // Insert a 4th element using push_back:
    // this will cause the vector to resize the buffer
    vecBool.push_back (true);

    cout << "The contents of the vector are: " << endl << "{";
    for (size_t nIndex = 0; nIndex < vecBool.size (); ++ nIndex)
        cout << vecBool [nIndex] << ' ';
    cout << "}" << endl << endl;

    vecBool.flip ();

    cout << "The flipped contents of the vector are: " << endl << "{";
    for (size_t nIndex = 0; nIndex < vecBool.size (); ++ nIndex)
        cout << vecBool [nIndex] << ' ';
    cout << "}";

    return 0;
}