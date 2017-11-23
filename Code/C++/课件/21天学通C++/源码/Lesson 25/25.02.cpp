// LISTING 25.2 - Performing Logical Operations Using a Bitset
#include <bitset>
#include <string>
#include <iostream>

int main ()
{
    using namespace std;

    // A bitset to hold 8-bits
    bitset <8> eightBits;
    cout << "Enter a 8-bit sequence: ";

    // Store user-supplied sequence into the bitset
    cin >> eightBits;
    cout << endl;

    // Supply info on number of 1s and 0s in it:
    cout << "The number of 1s in the input sequence: ";
    cout << eightBits.count () << endl;
    cout << "The number of 0s in the input sequence: ";
    cout << eightBits.size () - eightBits.count () << endl;

    // create a copy
    bitset <8> flipInput (eightBits);

    // flip the bits
    flipInput.flip ();
    cout << "The flipped version of the input sequence is: "
        << flipInput << endl << endl;

    // another 8-bit sequence to perform bitwise-ops against the first
    bitset <8> eightMoreBits;
    cout << "Enter another 8-bit sequence: ";
    cin >> eightMoreBits;
    cout << endl;

    cout << "Result of AND, OR and XOR between the two sequences:" << endl;
    cout << eightBits << " & " << eightMoreBits << " = "
        << (eightBits & eightMoreBits) // bitwise AND
        << endl;

    cout << eightBits << " | " << eightMoreBits << " = "
        << (eightBits | eightMoreBits) // bitwise OR
        << endl;

    cout << eightBits << " ^ " << eightMoreBits << " = "
        << (eightBits ^ eightMoreBits) // bitwise XOR
        << endl;

    return 0;
}