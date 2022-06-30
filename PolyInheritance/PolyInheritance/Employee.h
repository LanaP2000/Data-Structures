#include <iostream>

#ifndef EMPLOYEE
#define EMPLOYEE

class Employee
{
public:
    Employee(string name = " ", long id = 0, char c = ' ', double sal = 0);
    virtual void display(ostream& out, double benefit = 0) const;
    virtual double calcSalary(ostream& out, double benefit = 0) const;

private:
    string Name; //name
    long EmpID; //id
    char Class; //c
    double salary; //sal
};

//--- Definition of Employee's Constructor
inline Employee::Employee(string name, long id, char c, double sal)
    : Name(name), EmpID(id), Class(c), salary(sal)
{ }

//--- Definition of Employee's display()
inline void Employee::display(ostream& out, double benefit) const
{
    out << "Name: " << Name << ' ' << endl;
    out << "Employee ID: " << EmpID << ' ' << endl;
    out << "Class: " << Class << ' ' << endl;
    out << "Base Salary: " << salary << ' ' << endl;
}

ostream& operator<<(ostream& out, const Employee& emp)
{
    emp.display(out);
    return out;
}
//--- Definition of calcSalary()
inline double Employee::calcSalary(ostream& out, double benefit) const
{
    return salary;
};
#endif
