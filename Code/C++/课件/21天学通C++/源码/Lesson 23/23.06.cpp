// LISTING 23.6 - Using std::transform with Unary and Binary Functions
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <functional>

int main ()
{
    using namespace std;

    string strSample ("THIS is a TEst string!");
    cout << "The sample string is: " << strSample << endl;

    string strLowerCaseCopy;
    strLowerCaseCopy.resize (strSample.size ());

    transform ( strSample.begin () // start of source range
        , strSample.end () // end of source range
        , strLowerCaseCopy.begin ()// start of destination range
        , tolower ); // unary function

    cout << "Result of 'transform' on the string with 'tolower':" << endl;
    cout << "\"" << strLowerCaseCopy << "\"" << endl << endl;

    // Two sample vectors of integers...
    vector <int> vecIntegers1, vecIntegers2;
    for (int nNum = 0; nNum < 10; ++ nNum)
    {
        vecIntegers1.push_back (nNum);
        vecIntegers2.push_back (10 - nNum);
    }

    // A destination range for holding the result of addition
    deque <int> dqResultAddition (vecIntegers1.size ());

    transform ( vecIntegers1.begin () // start of source range 1
        , vecIntegers1.end () // end of source range 1
        , vecIntegers2.begin () // start of source range 2
        , dqResultAddition.begin ()// start of destination range
        , plus <int> () ); // binary function

    cout << "Result of 'transform' using binary function 'plus': " << endl;
    cout <<endl << "Index Vector1 + Vector2 = Result (in Deque)" << endl;
    for (size_t nIndex = 0; nIndex < vecIntegers1.size (); ++ nIndex)
    {
        cout << nIndex << " \t " << vecIntegers1 [nIndex] << "\t+ ";
        cout << vecIntegers2 [nIndex] << " \t = ";

        cout << dqResultAddition [nIndex] << endl;
    }

    return 0;
}