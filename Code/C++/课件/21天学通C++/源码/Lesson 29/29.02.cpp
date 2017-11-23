// LISTING 29.2 A Simple assert() Macro
#define DEBUG
#include <iostream>
using namespace std;

#ifndef DEBUG
#define ASSERT(x)
#else
#define ASSERT(x) \
    if (! (x)) \
{ \
    cout << "ERROR!! Assert " << #x << " failed << endl; \
    cout << " on line " << __LINE__ << endl; \
    cout << " in file " << __FILE__ << endl; \
}
#endif

int main()
{
    int x = 5;
    cout << "First assert: " << endl;
    ASSERT(x==5);
    cout << "\nSecond assert: " << endl;
    ASSERT(x != 5);
    cout << "\nDone. << endl";
    return 0;
}