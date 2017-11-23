// LISTING 12.6 - Illustration of the Use of Virtual Inheritance
#include <iostream>
using namespace std;

typedef int HANDS;
enum COLOR { Red, Green, Blue, Yellow, White, Black, Brown } ;

class Animal // common base to both horse and bird
{
public:
    Animal(int);
    virtual ~Animal() { cout << "Animal destructor...\n"; }
    virtual int GetAge() const { return itsAge; }
    virtual void SetAge(int age) { itsAge = age; }
private:
    int itsAge;
};

Animal::Animal(int age):
itsAge(age)
{
    cout << "Animal constructor...\n";
}

class Horse : virtual public Animal
{
public:
    Horse(COLOR color, HANDS height, int age);
    virtual ~Horse() { cout << "Horse destructor...\n"; }
    virtual void Whinny()const { cout << "Whinny!... "; }
    virtual HANDS GetHeight() const { return itsHeight; }
    virtual COLOR GetColor() const { return itsColor; }
protected:
    HANDS itsHeight;
    ESSON 12: Polymorphism
        329417_ch12.qxd 5/29/08 1:25 PM Page 22
        COLOR itsColor;
};

Horse::Horse(COLOR color, HANDS height, int age):
Animal(age),
itsColor(color),itsHeight(height)
{
    cout << "Horse constructor...\n";
}

class Bird : virtual public Animal
{
public:
    Bird(COLOR color, bool migrates, int age);
    virtual ~Bird() {cout << "Bird destructor...\n"; }
    virtual void Chirp()const { cout << "Chirp... "; }
    virtual void Fly()const
    { cout << "I can fly! I can fly! I can fly! "; }
    virtual COLOR GetColor()const { return itsColor; }
    virtual bool GetMigration() const { return itsMigration; }
protected:
    COLOR itsColor;
    bool itsMigration;
};

Bird::Bird(COLOR color, bool migrates, int age):
Animal(age),
itsColor(color), itsMigration(migrates)
{
    cout << "Bird constructor...\n";
}

class Pegasus : public Horse, public Bird
{
public:
    void Chirp()const { Whinny(); }
    Pegasus(COLOR, HANDS, bool, long, int);
    virtual ~Pegasus() {cout << "Pegasus destructor...\n";}
    virtual long GetNumberBelievers() const
    { return itsNumberBelievers; }
    virtual COLOR GetColor()const { return Horse::itsColor; }
private:
    long itsNumberBelievers;
};

Pegasus::Pegasus(
                 COLOR aColor,
                 HANDS height,
                 bool migrates,
                 long NumBelieve,
                 int age):
                Horse(aColor, height,age),
                Bird(aColor, migrates,age),
                Animal(age*2),
                itsNumberBelievers(NumBelieve)
{
    cout << "Pegasus constructor...\n";
}

int main()
{
    Pegasus *pPeg = new Pegasus(Red, 5, true, 10, 2);
    int age = pPeg->GetAge();
    cout << "This pegasus is " << age << " years old.\n";
    delete pPeg;
    return 0;
}