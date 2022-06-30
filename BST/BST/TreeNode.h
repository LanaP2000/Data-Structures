/*
The file TreeNode.h shall consist of the class TreeNode. 
This class shall have BST as its friend class. 
*/
#pragma once
#include <iostream>
using namespace std;
#ifndef TREENODE_H
#define TREENODE_H
#include "BST.h"

class TreeNode
{
    friend class BST;
public:
  TreeNode();  //default constructor
  TreeNode(int i, TreeNode* L = 0, TreeNode* R = 0); //explicit value constructor
  int getItem() const; // accessor function

private:
  int item; //i
  TreeNode* Lchild; //L
  TreeNode* Rchild; //R

};

//--- Definition of default constructor
inline TreeNode::TreeNode()
{
    Lchild = Rchild = NULL;
}

//--- Definition of explicit value constructor
inline TreeNode::TreeNode(int i, TreeNode* L, TreeNode* R) 
    : item(i), Lchild(L), Rchild(R)
{}

//--- Definition of getter, accessor function
inline int TreeNode::getItem() const
{
    return item;
} 

#endif 
