#include <iostream>
using namespace std;
class OutOfMemory {};

int main()
{
    try
    {
        int *myInt = new int;
        if (myInt == 0)
            throw OutOfMemory();
    }
    catch (OutOfMemory)
    {
        cout << "Unable to allocate memory!" << endl;
    }
    return 0;
}