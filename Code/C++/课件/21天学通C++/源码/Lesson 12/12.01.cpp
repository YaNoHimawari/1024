// LISTING 12.1 - Getting Horses to Fly with Single Inheritance 
#include <iostream>
using namespace std;

class Horse
{
public:
    void Gallop(){ cout << "Galloping...\n"; }
    virtual void Fly() { cout << "Horses can't fly.\n" ; }
private:
    int itsAge;
};

class Pegasus : public Horse
{
public:
    void Fly()
    {cout<<"I can fly! I can fly! I can fly!\n";}
};

const int NumberHorses = 5;
int main()
{
    Horse* Ranch[NumberHorses];
    Horse* pHorse;
    int choice,i;
    for (i=0; i<NumberHorses; i++)
    {
        cout << "(1)Horse (2)Pegasus: ";
        cin >> choice;
        if (choice == 2)
            pHorse = new Pegasus;
        else
            pHorse = new Horse;
        Ranch[i] = pHorse;
    }
    cout << endl;
    for (i=0; i<NumberHorses; i++)
    {
        Ranch[i]->Fly();
        delete Ranch[i];
    }
    return 0;
}