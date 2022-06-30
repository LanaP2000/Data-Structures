//-- Driver.cpp --------------------------------------------------------------

#include <iostream>
using namespace std;

#include "Stackqueue.h"

int main()
{
    int integer;
    char choice;
    int userChoice;
    char again;
    int odd;
    int even;
    Stackqueue s;
    cout << "Stack created.  Empty? " << boolalpha << s.empty() << endl;
    cout << "Press \"Y\" or \"y\" to continue\n";
    cin >> choice;
    while (choice == 'Y' || choice == 'y')
    {
        cout << "************ Menu ************";
        cout << "\n1. Insert a number"; //8 6 4 2 1 3 9 
        cout << "\n2. Insert an odd number";
        cout << "\n3. Insert an even number";
        cout << "\n4. Delete an even number";
        cout << "\n5. Delete an odd number";
        cout << "\n6. Delete two even numbers and one odd number"; //4 2 1 3 ---> LIFO
        cout << "\n7. Display staque";
        cout << "\n8. Exit " << endl;
        cout << "\n   Enter choice : ";
        cin >> userChoice;

        switch (userChoice)
        {
        case 1:
            cout << "\nEnter any integer to insert: ";
            cin >> integer;
            if (integer % 2 == 0)
                s.pushFront(integer);
            else if (integer % 2 != 0)
                s.pushBack(integer);
            break;
        
        case 2:
            cout << "\nEnter an odd number to insert: ";
            cin >> odd;
            s.pushBack(odd);
            break;
        
        case 3:
            cout << "\nEnter an even number to insert: ";
            cin >> even;
            s.pushFront(even);
            break;
        
        case 4:
            s.popFront();
            break;
        
        case 5:
            s.popBack();
            break;
        
        case 6:
            if (!(s.empty()))
            {
                s.popFront();
                s.popFront();
                s.popBack();
            }
            else
                cout << "*** Staque is empty -- can't remove a value ***\n\n\n";
            break;
        
        case 7:
            if (!(s.empty()))
            {
                cout << "Contents of staque:\n";
                s.display(cout);
                cout << endl;
            }
            else
                cout << " ***Staque is empty -- can't remove a value ***\n\n\n";
            break;
        
        case 8:
            break;
        
        default:
            cout << "Oops... Something went wrong.\n";
        }
        cout << "Wanna play with the staque again? (y/n)\n";
        cin >> again;
        if (again == 'Y' || again == 'y')
            continue;   
        if (again == 'N' || again == 'n')
            cout << "Bye\n"; // if no, bye
        break; //break and finish the program successfully!
    }
}
