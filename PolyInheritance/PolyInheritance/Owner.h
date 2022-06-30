#include "Employee.h"
#include <iostream>
using namespace std;

#ifndef OWNER
#define OWNER

class Owner : public Employee
{
public:
    Owner(string name = " ", long id = 0, char c = 'O', double sal = 15000, float profitPercentage = 0.6);

    virtual void display(ostream& out, double benefit = 0) const;
    virtual double calcSalary(ostream& out, double benefit = 0) const;
private:
    double Profit;
};

//--- Definition of Owner's Constructor
inline Owner::Owner(string name, long id, char c, double sal, float profitPercentage)
    : Employee(name, id, c, sal), Profit(profitPercentage)
{}

//--- Definition of Owner's display()
inline void Owner::display(ostream& out, double benefit) const
{
    double salary = 0;
    if (benefit < 0)
        Employee::display(out);
    else
    {
        Employee::display(out);
        out << "Profit: " << Profit * benefit << endl;
    }
}

//--- Definition of Owner's calcSalary()
inline double Owner::calcSalary(ostream& out, double benefit) const
{
    double salary = 0;
    if (benefit < 0)
        salary = (Employee::calcSalary(out)) + benefit;
    else
        salary = (Profit * benefit) + (Employee::calcSalary(out));
    out << "Total Salary: " << salary << endl;
    return salary;
}
#endif
