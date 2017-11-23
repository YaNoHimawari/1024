// LISTING 18.8 Demonstration of size() and capacity()
#include <iostream>
#include <vector>

int main ()
{
    using namespace std;

    // Instantiate a vector object that holds 5 integers of default value
    vector <int> vecDynamicIntegerArray (5);

    cout << "Vector of integers was instantiated with " << endl;
    cout << "Size: " << vecDynamicIntegerArray.size ();
    cout << ", Capacity: " << vecDynamicIntegerArray.capacity () << endl;

    // Inserting a 6th element in to the vector
    vecDynamicIntegerArray.push_back (666);

    cout << "After inserting an additional element... " << endl;
    cout << "Size: " << vecDynamicIntegerArray.size ();
    cout << ", Capacity: " << vecDynamicIntegerArray.capacity () << endl;

    // Inserting another element
    vecDynamicIntegerArray.push_back (777);

    cout << "After inserting yet another element... " << endl;
    cout << "Size: " << vecDynamicIntegerArray.size ();
    cout << ", Capacity: " << vecDynamicIntegerArray.capacity () << endl;

    return 0;
}