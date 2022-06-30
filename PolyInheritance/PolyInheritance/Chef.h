#include "Employee.h"
#include <string>
using namespace std;

#ifndef CHEF
#define CHEF

class Chef : public Employee
{
public:
    Chef(string name = " ", long id = 0, char c = 'C', double sal = 10000, string ce = " ", double profitPercentage = 0.2);

    virtual void display(ostream& out, double benefit = 0) const;
    virtual double calcSalary(ostream& out, double benefit = 0) const;

private:
    double Profit;
    string CE; // Cuisine Expertise
    Chef(string name, long id, string c, double sal, double profit);
};

//--- Definition of Chef's Constructor
inline Chef::Chef(string name, long id, char c, double sal, string ce, double profitPercentage)
    : Employee(name, id, c, sal), CE(ce), Profit(profitPercentage)
{ }

//--- Definition of Chef's display()
inline void Chef::display(ostream& out, double benefit) const
{
    double salary = 0;
    Employee::display(out);    //inherited members
    out << "Profit: " << Profit * benefit << endl; //local members
    out << "Cuisine Expertise: " << CE << endl;   //local members
}


//--- Definition of Chef's calcSalary()
inline double Chef::calcSalary(ostream& out, double benefit) const
{
    double salary = 0;
    if (benefit < 0)
        benefit = 0;
    else
        salary = (Profit * benefit) + (Employee::calcSalary(out));
    out << "Salary: " << salary << endl;
    return salary;
}

#endif
