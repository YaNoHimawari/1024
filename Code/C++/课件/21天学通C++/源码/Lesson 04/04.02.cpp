// Listing 4.2 demonstrates what writing past the bounds of an array is!

#include <iostream>
using namespace std;

int main()
{
    long TargetArray[25]; // array to fill

    int i;
    for (i=0; i<25; i++)
        TargetArray[i] = 10;

    cout << "Test 1: \n"; // test current values (should be 0)
    cout << "TargetArray[0]: " << TargetArray[0] << endl; // lower bound
    cout<<"TargetArray[24]: "<<TargetArray[24]<<endl<<endl; // upper bound

    cout << "\nAttempting at assigning values beyond the upper-bound...";
    for (i = 0; i<=25; i++) // Going a little too far!
        TargetArray[i] = 20; // Assignment may fail for element [25]

    cout << "\nTest 2: \n";
    cout << "TargetArray[0]: " << TargetArray[0] << endl;
    cout << "TargetArray[24]: " << TargetArray[24] << endl;
    cout<<"TargetArray[25]: "<<TargetArray[25]<<endl<<endl; // out of bounds

    return 0;
}