// LISTING 9.9 - Passing Objects by Reference
#include <iostream>

using namespace std;
class SimpleCat
{
public:
    SimpleCat (); // constructor
    SimpleCat(SimpleCat&); // copy constructor
    ~SimpleCat(); // destructor
};

SimpleCat::SimpleCat()
{
    cout << "Simple Cat Constructor..." << endl;
}

SimpleCat::SimpleCat(SimpleCat&)
{
    cout << "Simple Cat Copy Constructor..." << endl;
}

SimpleCat::~SimpleCat()
{
    cout << "Simple Cat Destructor..." << endl;
}

SimpleCat FunctionOne (SimpleCat theCat);
SimpleCat* FunctionTwo (SimpleCat *theCat);

int main()
{
    cout << "Making a cat..." << endl;
    SimpleCat Frisky;
    cout << "Calling FunctionOne..." << endl;
    FunctionOne(Frisky);
    cout << "Calling FunctionTwo..." << endl;
    FunctionTwo(&Frisky);
    return 0;
}

// FunctionOne, passes by value
SimpleCat FunctionOne(SimpleCat theCat)
{
    cout << "Function One. Returning... " << endl;
    return theCat;
}

// functionTwo, passes by reference
SimpleCat* FunctionTwo (SimpleCat *theCat)
{
    cout << "Function Two. Returning... " << endl;
    return theCat;
}