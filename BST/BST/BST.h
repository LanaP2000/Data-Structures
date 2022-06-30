/*
The file BST.h shall contain the class declaration of class BST. 
In addition to the public member functions, have 4 utility functions 
which will help you to perform the search, preorder, postorder and inorder traversal operations.
*/
#pragma once
#include "TreeNode.h"
#include <iostream>
using namespace std;
#ifndef BST_H
#define BST_H

class BST
{
public:
    BST(); //default constructor
    bool empty() const; //empty function to check whether BST is empty or not
    bool search(const int Item) const; //search function to search an item in BST
    void insert(const int Item); //insert function to insert an item in BST
    void remove(const int Item); //remove function to remove an item from BST
    void inorder(ostream& out) const; //inorder function to perform inorder traverse on BST
    void preorder(ostream& out) const; //preorder function to perform preorder traverse on BST
    void postorder(ostream& out) const; //postorder function to perform postorder traverse on BST
    void display(ostream& out) const; //in cpp file it will be called for inorder traverse
    
    
private:
    typedef TreeNode* TreeNodePointer;
    TreeNodePointer Root;
 
    void removeAux(const int Item, bool & found, TreeNodePointer& nodeData, TreeNodePointer& parent) const; //locate a node and its parent
    void inorderAux(ostream& out, TreeNodePointer branchRoot) const; //inorder traverse help function
    void preorderAux(ostream& out, TreeNodePointer branchRoot) const; //preorder traverse help function
    void postorderAux(ostream& out, TreeNodePointer branchRoot) const; //postorder traverse help function
}; 

#endif
