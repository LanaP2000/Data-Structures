/*
The file driver.cpp should test all the functionalities that you have incorporated for the BST:
search, preorder, postorder and inorder traversal
This program requires you to implement a Binary Search Tree with the following operations to be executed on the tree :
1)	Insert a node in the tree
2)	Delete a node from the tree
3)	Search for an element in the tree
4)	Traverse the tree in Preorder, Inorder and Postorder fashion
5)	Print the contents of the tree in preorder fashion

*/

using namespace std;
#include <iostream>
#include "BST.h"
#include "TreeNode.h"

int main()
{
	BST B;
	char continueorexit;
	int userChoice;
	int number;

	cout << "Constructing empty BST\n";
	cout << "BST " << (B.empty() ? "is" : "is not") << " empty\n\n";
	cout << "BST is created. Want to continue?\n";
	cout << "Press \"Y\" or \"y\" to continue\n";
	cin >> continueorexit;
	while (continueorexit == 'Y' || continueorexit == 'y')
	{

		
		cout << "************ MENU ************\n\n";
		cout << "1)	Insert a node in the tree\n";
		cout << "2)	Delete a node from the tree\n";
		cout << "3)	Search for an element in the tree\n";
		cout << "4)	Traverse the tree in Preorder fashion\n";
		cout << "5)	Traverse the tree in Inorder fashion\n";
		cout << "6)	Traverse the tree in Postorder fashion\n";
		cout << "7)	Display the BST in inorder fashion\n";
		cout << "8)	Exit\n\n";
		cout << "Choose an option. Press 1, 2, 3, 4, 5, 6 or 7.\n";

		cin >> userChoice;

		switch (userChoice)
		{
		case 1:
			for (;;)
			{
				cout << "Insert a number (-999 to stop): ";
				cin >> number;
				if (number == -999) 
					break;
				B.insert(number);
				cout << "\n\n";
			}
			break;
		case 2:
			for (;;)
			{
				cout << "Remove a number (-999 to stop): ";
				cin >> number;
				if (number == -999) 
					break;
				B.remove(number);
				cout << "\n\n";
			}
			break;
		case 3:
			for (;;)
			{
				cout << "Item to find (-999 to stop): ";
				cin >> number;
				if (number == -999) 
					break;
				cout << (B.search(number) ? "Found" : "Not found") << endl;
			}
			cout << "\n\n";
			break;
		case 4:
			if (!B.empty())
			{
				cout << "Preorder Traversal of BST: \n";
				B.preorder(cout);
				cout << "\n\n";
			}
			else
				cout << "BST is empty!\n\n";
			break;
		case 5:
			if (!B.empty())
			{
				cout << "Inorder Traversal of BST: \n\n";
				B.inorder(cout);
				cout << "\n\n";
			}
			else
				cout << "BST is empty!\n";
			break;
		case 6:
			if (!B.empty())
			{
				cout << "Postorder Traversal of BST: \n\n";
				B.postorder(cout);
				cout << "\n\n";
			}
			else
				cout << "BST is empty!\n\n";
			break;
		case 7:
			if (!B.empty())
			{
				B.display(cout);
				cout << "\n\n";
			}
			else
				cout << "BST is empty!\n\n";
			break;
		case 8:
			cout << "Bye!\n\n";
			return 0;
		default:
			cout << "Oops... Something went wrong...\n";
			return 0;
			break;
		}

	}

	return 0;
}
