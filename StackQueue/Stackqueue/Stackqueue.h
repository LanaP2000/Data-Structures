//--- Stackqueue.h --------------------------------------------------------------
#include <iostream>
using namespace std;

#ifndef STACKQUEUE
#define STACKQUEUE

typedef int StaqueElement;

class Stackqueue
{
public:
    Stackqueue(); //Default value constructor
    Stackqueue(const Stackqueue& original); //Explicit value constructor
    ~Stackqueue(); //Destructor to deallocate memory

    const Stackqueue& operator= (const Stackqueue& Right); //The current stack becomes copy of right

    StaqueElement Front() const; //Value at the front of stack is returned if not empty; if empty, garbage
    StaqueElement Back() const; //Value at the back of stack is returned if not empty; if empty, garbage

    bool empty() const; //Checkes whether stack is empty or not
    void pushFront(const StaqueElement& value); // Value is added at the front of stack - even
    void pushBack(const StaqueElement& value); //Value is added at the back of stack - odd
    void display(ostream& out) const; //Outputting stack's contents from top to down
    void popFront(); // Remove even
    void popBack(); //Remove odd

private:
    //Node class
    class Node
    {
    public:
        StaqueElement data;
        Node* next;
        //--- Node constructor
        Node(StaqueElement value, Node* link = 0) // A node has been constructed and default values are given to members
            : data(value), next(link)
        {}
    };

    typedef Node* NodePointer;

    //Data members
    NodePointer myFront;      // pointer to front of stack
    NodePointer myBack;       // pointer to back of stack
    NodePointer rootNode;

}; // end of class declaration

#endif
