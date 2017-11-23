// LISTING 23.5 - Displaying the Contents of Sequences Using for_each
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Unary function object type invoked by for_each
template <typename elementType>
class DisplayElementKeepCount
{
private:
    int m_nCount;

public:
    DisplayElementKeepCount ()
    {
        m_nCount = 0;
    }

    void operator () (const elementType& element)
    {
        ++ m_nCount;
        cout << element << ' ';
    }

    int GetCount ()
    {
        return m_nCount;
    }
};

int main ()
{
    vector <int> vecIntegers;

    for (int nCount = 0; nCount < 10; ++ nCount)
        vecIntegers.push_back (nCount);

    cout << "Displaying the vector of integers: " << endl;

    // Display the array of integers
    DisplayElementKeepCount<int> mIntResult =
        for_each ( vecIntegers.begin () // Start of range
        , vecIntegers.end () // End of range
        , DisplayElementKeepCount<int> () );// Functor

    cout << endl;

    // Use the state stored in the return value of for_each!
    cout << "'" << mIntResult.GetCount () << "' elements ";
    cout << " in the vector were displayed!" << endl << endl;

    string strSample ("for_each and strings!");
    cout << "String sample is: " << strSample << endl << endl;

    cout << "String displayed using DisplayElementKeepCount:" << endl;
    DisplayElementKeepCount<char> mCharResult = for_each (strSample.begin()
        , strSample.end ()
        , DisplayElementKeepCount<char> () );
    cout << endl;

    cout << "'" << mCharResult.GetCount () << "' characters were displayed";

    return 0;
}