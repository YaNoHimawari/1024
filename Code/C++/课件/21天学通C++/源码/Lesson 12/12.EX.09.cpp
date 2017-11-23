class Vehicle
{
    virtual void Move() = 0;
    virtual void Haul() = 0;
};

class Car : public Vehicle
{
    virtual void Move();
};
class Bus : public Vehicle
{
    virtual void Move();
    virtual void Haul();
};
class SportsCar : public Car
{
    virtual void Haul();
};
class Coupe : public Car
{
    virtual void Haul();
};