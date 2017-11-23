// LISTING 14.1 Dynamic Casting That Helps Tell Whether an Animal Object Is a Cat or a Dog
#include <iostream>
using namespace std;

// Base class
class CAnimal
{
public:
    virtual void Speak () = 0;
};

class CDog : public CAnimal
{
public:
    void WagTail () {cout << "Dog: I wagged my tail!" << endl;}

    void Speak () {cout << "Dog: Bow-Wow!" << endl;}
};

class CCat : public CAnimal
{
public:
    void CatchMice () {cout << "Cat: I caught a mouse!" << endl;}

    void Speak () {cout << "Cat: Meow!" << endl;}
};

void DetermineType (CAnimal* pAnimal);

int main ()
{
    // pAnimal1 points to a Dog object
    CAnimal* pAnimal1 = new CDog ();

    // pAnimal2 points to a Cat object
    CAnimal* pAnimal2 = new CCat ();

    cout << "Using dynamic_cast to determine type of Animal 1" << endl;
    DetermineType (pAnimal1);

    cout << "Using dynamic_cast to determine type of Animal 2" << endl;
    DetermineType (pAnimal2);

    // Use the virtual function overridden by the subclasses to prove type
    cout << "Verifying type: Asking Animal 1 to speak!" << endl;
    pAnimal1->Speak ();

    cout << "Verifying type: Asking pAnimal 2 to speak!" << endl;
    pAnimal2->Speak ();

    return 0;
}

void DetermineType (CAnimal* pAnimal)
{
    CDog* pDog = dynamic_cast <CDog*>(pAnimal);
    if (pDog)
    {
        cout << "The animal is a dog!" << endl;

        // Call the derived class' function
        pDog->WagTail ();
    }

    CCat* pCat = dynamic_cast <CCat*>(pAnimal);
    if (pCat)
    {
        cout << "The animal is a cat!" << endl;

        pCat->CatchMice ();
    }
}