// LISTING 24.3 - Instantiating an STL Queue
#include <queue>
#include <list>

int main ()
{
    using namespace std;

    // A queue of integers
    queue <int> qIntegers;

    // A queue of doubles
    queue <double> qDoubles;

    // A queue of doubles stored internally in a list
    queue <double, list <double> > qDoublesInList;

    return 0;
}