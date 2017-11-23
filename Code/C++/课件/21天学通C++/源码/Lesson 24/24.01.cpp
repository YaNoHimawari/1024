// LISTING 24.1 - Instantiation of an STL Stack
#include <stack>
#include <vector>

int main ()
{
    using namespace std;

    // A stack of integers
    stack <int> stackIntegers;

    // A stack of doubles
    stack <double> stackDoubles;

    // A stack of doubles contained in a vector
    stack <double, vector <double> > stackDoublesInVector;

    return 0;
}