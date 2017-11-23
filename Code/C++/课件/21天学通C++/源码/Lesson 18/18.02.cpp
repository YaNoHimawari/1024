// LISTING 18.2 Inserting Elements in a Vector Using the push_back Method
#include <iostream>
#include <vector>

int main ()
{
    std::vector <int> vecDynamicIntegerArray;

    // Insert sample integers into the vector:
    vecDynamicIntegerArray.push_back (50);
    vecDynamicIntegerArray.push_back (1);
    vecDynamicIntegerArray.push_back (987);
    vecDynamicIntegerArray.push_back (1001);

    std::cout << "The vector contains ";
    std::cout << vecDynamicIntegerArray.size () << " Elements";

    return 0;
}