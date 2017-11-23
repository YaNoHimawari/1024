// LISTING 24.5 - Instantiating an STL priority_queue
#include <queue>

int main ()
{
    using namespace std;

    // A priority queue of integers sorted using std::less <> (default)
    priority_queue <int> pqIntegers;

    // A priority queue of doubles
    priority_queue <double> pqDoubles;

    // A priority queue of integers sorted using std::greater <>
    priority_queue <int, deque <int>, greater <int> > pqIntegers_Inverse;

    return 0;
}