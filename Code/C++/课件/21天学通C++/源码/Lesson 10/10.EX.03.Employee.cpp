// Employee.cpp
#include <iostream>
#include "10.EX.02.Employee.h"
int Employee::GetAge() const
{
    return itsAge;
}
void Employee::SetAge(int age)
{
    itsAge = age;
}
int Employee::GetYearsOfService() const
{
    return itsYearsOfService;
}
void Employee::SetYearsOfService(int years)
{
    itsYearsOfService = years;
}
int Employee::GetSalary()const
{
    return itsSalary;
}
void Employee::SetSalary(int salary)
{
    itsSalary = salary;
}
int main()
{
    using namespace std;
    Employee John;
    Employee Sally;
    John.SetAge(30);
    John.SetYearsOfService(5);
    John.SetSalary(50000);
    Sally.SetAge(32);
    Sally.SetYearsOfService(8);
    Sally.SetSalary(40000);
    cout << "At AcmeSexist company, John and Sally have ";
    cout << "the same job.\n\n";
    cout << "John is " << John.GetAge() << " years old." << endl;
    cout << "John has been with the firm for " ;
    cout << John.GetYearsOfService() << " years." << endl;
    cout << "John earns $" << John.GetSalary();
    cout << " dollars per year.\n\n";
    cout << "Sally, on the other hand is " << Sally.GetAge();
    cout << " years old and has been with the company ";
    cout << Sally.GetYearsOfService();
    cout << " years. Yet Sally only makes $" << Sally.GetSalary();
    cout << " dollars per year! Something here is unfair.";
}