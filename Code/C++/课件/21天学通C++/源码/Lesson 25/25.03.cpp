// LISTING 25.3 - The Instantiation of Vector<bool>
#include <vector>

int main ()
{
    using namespace std;

    // Instantiate an object using the default constructor
    vector <bool> vecBool1;

    // A vector of 10 elements with value true (default: false)
    vector <bool> vecBool2 (10, true);

    // Instantiate one object as a copy of another
    vector <bool> vecBool2Copy (vecBool2);

    return 0;
}