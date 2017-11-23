// Listing 13.3: How smart pointers that simulate normal pointer semantics
#include <memory>
#include <iostream>
using namespace std;

class Dog
{
public:
    Dog () {}; // Constructor
    ~Dog () {}; // Destructor

    void Bark ()
    {
        cout << "Bark! Bark!" << endl;
    }
};

int main ()
{
    // a smart pointer equivalent of an int*
    auto_ptr <int> pSmartIntPtr (new int);

    // Use this smart pointer like any normal pointer...
    *pSmartIntPtr = 25;
    cout << "*pSmartIntPtr = " << *pSmartIntPtr << endl;

    // a smart pointer equivalent of a Dog*
    auto_ptr <Dog> pSmartDog (new Dog);

    // Use this smart pointer like any ordinary pointer
    pSmartDog->Bark ();

    return 0;
}