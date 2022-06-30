#include "Employee.h"
#include <string>
using namespace std;

#ifndef WAITER
#define WAITER

class Waiter : public Employee
{
public:
    Waiter(string name = " ", long id = 0, char c = 'W', double sal = 3000, double tip = 0, int ys = 0);

    virtual void display(ostream& out, double monthly_tip = 0) const;
    virtual double calcSalary(ostream& out, double monthly_tip = 0) const;

private:
    double Tip;
    int YS; //years of service
};

//--- Definition of Waiter's Constructor
inline Waiter::Waiter(string name, long id, char c, double sal, double tip, int ys)
    : Employee(name, id, c, sal), Tip(tip), YS(ys)
{ }

//--- Definition of Waiter's display()
inline void Waiter::display(ostream& out, double monthly_tip) const
{
    double salary = 0;
    Employee::display(out);    //inherited members
    out << "Tip: " << Tip << endl; //local members
    out << "Years of service " << YS << endl;   //local members
}

//--- Definition of Waiter's calcSalary()
inline double Waiter::calcSalary(ostream& out, double monthly_tip) const {
    double salary = 0;
    salary = Tip + (Employee::calcSalary(out));
    out << "Total Salary: " << salary << endl;
    return salary;
}
#endif
