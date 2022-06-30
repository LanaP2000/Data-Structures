//--- Stackqueue.cpp --------------------------------------------------------------

using namespace std;
#include <new>
#include "Stackqueue.h"

//--- Definition of Stack constructor
Stackqueue::Stackqueue()
    : myFront(0), myBack(0), rootNode(0)
{}

//--- Definition of Stack copy constructor
Stackqueue::Stackqueue(const Stackqueue& origS)
{
    myFront = 0;
    myBack = 0;
    if (!origS.empty())
    {
        // Copy first node
        myFront = new Stackqueue::Node(origS.Front());
        myBack = new Stackqueue::Node(origS.Back());

        // Set pointers to run through the stack's linked lists
        Stackqueue::NodePointer lPtr1 = myFront,
            oPtr1 = origS.myFront->next;
        Stackqueue::NodePointer lPtr2 = myBack,
            oPtr2 = origS.myBack->next;

        while (oPtr1 != 0)
        {
            lPtr1->next = new Stackqueue::Node(oPtr1->data);
            lPtr1 = lPtr1->next;
            oPtr1 = oPtr1->next;
        }

        while (oPtr2 != 0)
        {
            lPtr2->next = new Stackqueue::Node(oPtr2->data);
            lPtr2 = lPtr2->next;
            oPtr2 = oPtr2->next;
        }
    }
}

//--- Definition of Stack destructor
Stackqueue::~Stackqueue()
{
    // Set pointers to run through the stack
    Stackqueue::NodePointer cPtr1 = myFront,  // node to be deallocated
                                    nPtr1; // its successor
    Stackqueue::NodePointer cPtr2 = myBack,   // node to be deallocated
                                    nPtr2; // its successor
    while (cPtr1 != 0)
    {
        nPtr1 = cPtr1->next;
        delete cPtr1;
        cPtr1 = nPtr1;
    }
    while (cPtr2 != 0)
    {
        nPtr2 = cPtr2->next;
        delete cPtr2;
        cPtr2 = nPtr2;
    }
}

//--- Definition of assignment operator
const Stackqueue& Stackqueue::operator = (const Stackqueue& Right)
{
    if (this != &Right)         
    {
        this->~Stackqueue();     //Destroy current linked list
        if (Right.empty())       //Make stack empty
        {
            myFront = 0;
            myBack = 0;
        }
        else
        {                                //Copy the list on the righthandside
           // Copy first node
            myFront = new Stackqueue::Node(Right.Front());
            myBack = new Stackqueue::Node(Right.Back());

            //Set pointers to run through the stacks' linked lists
            Stackqueue::NodePointer lPtr1 = myFront,
                rPtr1 = Right.myFront->next;
            Stackqueue::NodePointer lPtr2 = myBack,
                rPtr2 = Right.myBack->next;

            while (rPtr1 != 0)
            {
                lPtr1->next = new Stackqueue::Node(rPtr1->data);
                lPtr1 = lPtr1->next;
                rPtr1 = rPtr1->next;
            }
            while (rPtr2 != 0)
            {
                lPtr2->next = new Stackqueue::Node(rPtr2->data);
                lPtr2 = lPtr2->next;
                rPtr2 = rPtr2->next;
            }
        }
    }
    return *this;
}

//Definition of empty()
bool Stackqueue::empty() const
{
    return ((myFront == 0) && (myBack == 0));
}

//Definition of pushFront() 
void Stackqueue::pushFront(const StaqueElement& value)
{
    if (value % 2 == 0)
    {
        if (myFront == 0)
            myFront = new Stackqueue::Node(value, myBack);
        else
            myFront = new Stackqueue::Node(value, myFront);
    }
}

//Definition of pushBack()
void Stackqueue::pushBack(const StaqueElement& value)
{
    if (value % 2 != 0)
    {
        if (myBack == 0)
            myBack = new Stackqueue::Node(value);
        if (myFront == 0)
            myFront = new Stackqueue::Node(0, myBack);
        else
        {
            Stackqueue::NodePointer temp = new Stackqueue::Node(value);
            myBack->next = temp;
            rootNode = myBack;
            myBack = temp;
        }
    }
}

//Definition of display()
void Stackqueue::display(ostream& out) const
{
    Stackqueue::NodePointer ptr;
    for (ptr = myFront; ptr != 0; ptr = ptr->next)
        out << ptr->data << endl;
}

//Definition of Front()
StaqueElement Stackqueue::Front() const
{
    if (!empty())
        return (myFront->data);
    else
    {
        cerr << "*** Stack is empty "
            " It's gonna return garbage ***\n";
        StaqueElement* temp = new(StaqueElement);
        StaqueElement garbage = *temp;     // garbage
        delete temp;
        return garbage;
    }
}

//Definition of Back()
StaqueElement Stackqueue::Back() const
{
    if (!empty())
        return (myBack->data);
    else
    {
        cerr << "*** Stack is empty "
            " It's gonna return garbage ***\n";
        StaqueElement* temp = new(StaqueElement);
        StaqueElement garbage = *temp;     // Garbage
        delete temp;
        return garbage;
    }
}

//Definition of popFront()
void Stackqueue::popFront()
{
    if (!empty())
    {
        Stackqueue::NodePointer ptr = myFront;
        myFront = myFront->next;
        delete ptr;
    }
    else
        cerr << "*** Staque is empty -- can't remove a value ***\n";
}

void Stackqueue::popBack()
{
    if (!empty())
    {
        Stackqueue::NodePointer ptr = myBack;
        myBack = rootNode;
        myBack->next = 0;
        delete ptr;
    }
    else
        cerr << "*** Staque is empty -- can't remove a value ***\n";
}



