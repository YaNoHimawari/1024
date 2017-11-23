// LISTING 25.1 - Instantiating a std::bitset
#include <bitset>
#include <iostream>
#include <string>

int main ()
{
    using namespace std;

    // instantiate a bitset object for holding 4 bits
    // all initialized to '0000'
    bitset <4> fourBits;
    cout << "The initial contents of fourBits: " << fourBits << endl;

    // instantiate a bitset object for holding 5 bits
    // initialize it to a bit sequence supplied by a string
    bitset <5> fiveBits (string ("10101"));
    cout << "The initial contents of fiveBits: " << fiveBits << endl;

    // instantiate a bitset object for 8 bits
    // given an unsigned long init value
    bitset <8> eightbits (255);
    cout << "The initial contents of eightBits: " << eightbits << endl;

    return 0;
}