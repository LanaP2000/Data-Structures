#include <iostream>
using namespace std;
#include "Employee.h"
#include "Owner.h"
#include "Chef.h"
#include "Waiter.h"

int main()
{
    Employee* ptr;
    double profit;
    double tip1;
    double tip2;
    double tip3;
    cout << "Enter monthly profit: " << endl;
    cin >> profit;

    cout << "Want to know who is the Owner?\n\n";
    cout << "There it is:\n";
    ptr = new Owner("Don Draper", 1, 'O', 15000);
    ptr->display(cout, profit);
    ptr->calcSalary(cout, profit);
    cout << "\n";

    ptr = new Chef("Betty", 2, 'C', 10000, "Italian");
    ptr->display(cout, profit);
    ptr->calcSalary(cout, profit);
    cout << "\n";

    ptr = new Chef("Megan", 3, 'C', 10000, "French");
    ptr->display(cout, profit);
    ptr->calcSalary(cout, profit);
    cout << "\n";

    cout << "Enter tip for the first waitress: \n";
    cin >> tip1;
    cout << "\n",

        ptr = new Waiter("Joan", 4, 'W', 3000, tip1, 3);
    ptr->display(cout, tip1);
    ptr->calcSalary(cout, tip1);
    cout << "\n";

    cout << "Enter tip for the second waitress: \n";
    cin >> tip2;
    cout << "\n",

        ptr = new Waiter("Pete", 5, 'W', 3000, tip2, 5);
    ptr->display(cout, tip2);
    ptr->calcSalary(cout, tip2);
    cout << "\n";

    cout << "Enter tip for the third waitress: \n";
    cin >> tip3;
    cout << "\n",

        ptr = new Waiter("Sally", 6, 'W', 3000, tip3, 7);
    ptr->display(cout, tip3);
    ptr->calcSalary(cout, tip3);
    cout << "\n";
}