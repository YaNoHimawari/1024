// LISTING 22.2 - Use a Function Object to Hold State
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename elementType>
struct DisplayElementKeepCount
{
    // Hold the count in a member variable
    int m_nCount;

    // Constructor
    DisplayElementKeepCount ()
    {
        m_nCount = 0;
    }

    // Display the element, hold count!
    void operator () (const elementType& element)
    {
        ++ m_nCount;
        cout << element << ' ';
    }
};

int main ()
{
    vector <int> vecIntegers;

    for (int nCount = 0; nCount < 10; ++ nCount)
        vecIntegers.push_back (nCount);

    cout << "Displaying the vector of integers: " << endl;

    // Display the array of integers
    DisplayElementKeepCount <int> mResult;
    mResult = for_each ( vecIntegers.begin () // Start of range
        , vecIntegers.end () // End of range
        , DisplayElementKeepCount <int> () );// function object

    cout << endl << endl;

    // Use the state stores in the return value of for_each!
    cout << "'" << mResult.m_nCount << "' elements were displayed!" << endl;

    return 0;
}