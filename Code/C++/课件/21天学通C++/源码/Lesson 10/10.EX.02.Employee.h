// Employee.h
class Employee
{
public:
    int GetAge() const;
    void SetAge(int age);
    int GetYearsOfService() const;
    void SetYearsOfService(int years);
    int GetSalary() const;
    void SetSalary(int salary);

private:
    int itsAge;
    int itsYearsOfService;
    int itsSalary;
};