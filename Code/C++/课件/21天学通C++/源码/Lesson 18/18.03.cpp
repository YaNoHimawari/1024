// LISTING 18.3 - Accessing elements in a vector using array-semantics
#include <vector>
#include <iostream>

int main ()
{
    std::vector <int> vecDynamicIntegerArray (4);

    // Copy integer values into individual element locations
    vecDynamicIntegerArray [0] = 50;
    vecDynamicIntegerArray [1] = 1;
    vecDynamicIntegerArray [2] = 987;
    vecDynamicIntegerArray [3] = 1001;

    std::cout << "The vector contains ";
    std::cout << vecDynamicIntegerArray.size () << " Elements";

    return 0;
}