/*
The file BST.cpp shall contain the public function descriptions that were declared in file BST.h.
*/

#include <iostream>
using namespace std;

#include "BST.h"
#include "TreeNode.h"

//--- Definition of constructor
BST::BST()
    : Root(0)
{}

//--- Definition of empty()
bool BST::empty() const
{
    return Root == 0;
}

//--- Definition of search()
bool BST::search(const int Item) const
{
    TreeNodePointer nodeData = Root;
    bool found = false;
    while (!found && nodeData != 0)
    {
        if (Item < nodeData->item)       //if your number is less
            nodeData = nodeData->Lchild; //BST property: left
        else if (Item > nodeData->item)  //if your number is more
            nodeData = nodeData->Rchild; //BST property: right
        else                          
            found = true;
    }
    return found;
}

//--- Definition of insert()
void BST::insert(const int Item)
{
    TreeNodePointer nodeData = Root;   // search pointer
    TreeNodePointer parent = NULL;        // pointer to parent of current node
    bool found = false;     
    while (!found && nodeData != 0)
    {
        parent = nodeData; 
        if (Item < nodeData->item)       //BST property: if less
            nodeData = nodeData->Lchild; //go left
        else if (Item > nodeData->item)  //if more
            nodeData = nodeData->Rchild; //go right
        else                          
            found = true;
    }
    if (!found) //if NOT found, construct a node
    {                               
        nodeData = new TreeNode(Item);
        if (parent == 0)               // if tree is empty
            Root = nodeData;           //your inserted item will become a root
        else if (Item < parent->item)  //again BST property in the next few lines
            parent->Lchild = nodeData;
        else if (Item > parent->item)  
            parent->Rchild = nodeData;
    }
    else
        cout << "Item you are trying to insert is already in the tree!\n";
}

//--- Definition of remove()
void BST::remove(const int Item)
{
    bool found;                     
    TreeNodePointer Pointer;      //pointer to a node you choose to delete                   
    TreeNodePointer parent;                   
    removeAux(Item, found, Pointer, parent);

    if (!found)
    {
        cout << "Item you are searching for is not in the BST!\n";
        return;
    }

    if (Pointer->Lchild != 0 && Pointer->Rchild != 0) //if a node has 2 children
    {                                
        TreeNodePointer nextPointer = Pointer->Rchild;
        parent = Pointer;
        while (nextPointer->Lchild != 0)       
        {
            parent = nextPointer;
            nextPointer = nextPointer->Lchild;
        }

        Pointer->item = nextPointer->item;
        Pointer = nextPointer;
    }

    TreeNodePointer branch = Pointer->Lchild;            
    if (branch == 0)
        branch = Pointer->Rchild;
    if (parent == 0)                  
        Root = branch;
    else if (parent->Lchild == Pointer)      
        parent->Lchild = branch;
    else                             
        parent->Rchild = branch;
    delete Pointer;
}

//--- Definition of inorder()
void BST::inorder(ostream& out) const
{
    inorderAux(out, Root);
}

//--- Definition of preorder()
void BST::preorder(ostream& out) const
{
    preorderAux(out, Root);
}

//--- Definition of postorder()
void BST::postorder(ostream& out) const
{
    postorderAux(out, Root);
}

//--- Definition of removeAux()
void BST::removeAux(const int Item, bool& found, TreeNodePointer& nodeData, TreeNodePointer& parent) const
{
    nodeData = Root;
    parent = 0;
    found = false;
    while (!found && nodeData != 0)
    {
        if (Item < nodeData->item)      
        {
            parent = nodeData;
            nodeData = nodeData->Lchild;
        }
        else if (Item > nodeData->item)  
        {
            parent = nodeData;
            nodeData = nodeData->Rchild;
        }
        else                          
            found = true;
    }
}

//--- Definition of inorderAux()
void BST::inorderAux(ostream& out, TreeNodePointer branchRoot) const
{
    if (branchRoot != 0)
    {
        inorderAux(out, branchRoot->Lchild);    // L 
        out << branchRoot->item << "  ";        // V 
        inorderAux(out, branchRoot->Rchild);    // R 
    }
}

//--- Definition of preorderAux()
void BST::preorderAux(ostream& out, TreeNodePointer branchRoot) const
{
    if (branchRoot != 0)
    {
        out << branchRoot->item << "  ";        // V 
        preorderAux(out, branchRoot->Lchild);   // L
        preorderAux(out, branchRoot->Rchild);   // R 
    }
}

//--- Definition of postorderAux()
void BST::postorderAux(ostream& out, TreeNodePointer branchRoot) const
{
    if (branchRoot != 0)
    {
        postorderAux(out, branchRoot->Lchild);    // L 
        postorderAux(out, branchRoot->Rchild);   // R 
        out << branchRoot->item << "  ";      // V 
    }
}

//--- Definition of graph()
void BST::display(ostream& out) const
{
    inorderAux(out, Root); //calling one method that I chose - inorder operation
}

