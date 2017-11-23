class Vehicle
{
    virtual void Move() = 0;
    virtual void Haul() = 0;
};
class Car : public Vehicle
{
    virtual void Move();
    virtual void Haul();
};
class Bus : public Vehicle
{
    virtual void Move();
    virtual void Haul();
};