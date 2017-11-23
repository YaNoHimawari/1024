// LISTING 12.9 - Implementing Pure Virtual Functions
#include <iostream>
using namespace std;

class Shape
{
public:
    Shape(){}
    virtual ~Shape(){}
    virtual double GetArea() = 0;
    virtual double GetPerim()= 0;
    virtual void Draw() = 0;
private:
};

void Shape::Draw()
{
    cout << "Abstract drawing mechanism!\n";
}

class Circle : public Shape
{
public:
    Circle(int radius):itsRadius(radius){}
    virtual ~Circle(){}
    double GetArea() { return 3.14 * itsRadius * itsRadius; }
    double GetPerim() { return 2 * 3.14 * itsRadius; }
    void Draw();
private:
    int itsRadius;
    int itsCircumference;
};

void Circle::Draw()
{
    cout << "Circle drawing routine here!\n";
    Shape::Draw();
}


class Rectangle : public Shape
{
public:
    Rectangle(int len, int width):
      itsLength(len), itsWidth(width){}
      virtual ~Rectangle(){}
      double GetArea() { return itsLength * itsWidth; }
      double GetPerim() {return 2*itsLength + 2*itsWidth; }
      virtual int GetLength() { return itsLength; }
      virtual int GetWidth() { return itsWidth; }
      void Draw();
private:
    int itsWidth;
    int itsLength;
};

void Rectangle::Draw()
{
    for (int i = 0; i<itsLength; i++)
    {
        for (int j = 0; j<itsWidth; j++)
            cout << "x ";

        cout << "\n";
    }
    Shape::Draw();
}


class Square : public Rectangle
{
public:
    Square(int len);
    Square(int len, int width);
    virtual ~Square(){}
    double GetPerim() {return 4 * GetLength();}
};

Square::Square(int len):
Rectangle(len,len)
{}

Square::Square(int len, int width):
Rectangle(len,width)

{
    if (GetLength() != GetWidth())
        cout << "Error, not a square... a Rectangle??\n";
}

int main()
{
    int choice;
    bool fQuit = false;
    Shape * sp;

    while (fQuit == false)
    {
        cout << "(1)Circle (2)Rectangle (3)Square (0)Quit: ";
        cin >> choice;

        switch (choice)
        {
        case 1: sp = new Circle(5);
            break;
        case 2: sp = new Rectangle(4,6);
            break;
        case 3: sp = new Square (5);
            break;
        default: fQuit = true;
            break;
        }
        if (fQuit == false)
        {
            sp->Draw();
            delete sp;
            cout << endl;
        }
    }
    return 0;
}