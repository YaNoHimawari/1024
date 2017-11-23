// LISTING 12.8 - Shape as an Abstract Base Class
class Shape
{
public:
    Shape(){}
    ~Shape(){}
    virtual double GetArea() = 0;
    virtual double GetPerim()= 0;
    virtual void Draw() = 0;
};