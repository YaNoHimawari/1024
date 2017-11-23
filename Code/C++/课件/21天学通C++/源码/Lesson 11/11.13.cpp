// LISTING 11.13 - Version of Class Fan Aggregating ElectricMotor
class Fan
{
public:
    Fan () {};
    ~Fan () {}

    void StartFan ()
    {
        m_ElectricMotor.StartMotor();
    }
    void StopFan ()
    {
        m_ElectricMotor.StopMotor ();
    }
private:
    ElectricMotor m_ElectricMotor;
};