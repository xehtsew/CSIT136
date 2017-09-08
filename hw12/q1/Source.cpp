/*
6. 
	a.Write the definition of the function to implement the nonrecursive
postorder traversal algorithm.
	b.Write a program to test the nonrecursive inorder, preorder, and postorder
traversal algorithms. (Note: First create a binary search tree.)

1. current = root; //start the traversal at the root node
2. v = 0;
3. if (current is NULL)
the binary tree is empty
4. if (current is not NULL)
a. push current into stack;
b. push 1 into stack;
c. current = current->llink;
d. while (stack is not empty)
	if (current is not NULL and v is 0) {
		push current and 1 into stack;
		current = current->llink;
	} else {
		pop stack into current and v;
		if (v == 1) {
			push current and 2 into stack;
			current = current->rlink;
			v = 0;
		} else
		visit current;
	}
*/

//5. Write a program to test various operations on a binary search tree.
#include "binarySearchTree.h"
#include <iostream>
#include <string>
using namespace std;
int main() {
	bSearchTreeType<int> tree;
	tree.isEmpty() == true ? cout << "our tree is empty" << endl : cout << "our tree is not empty." << endl;
	int num;
	cout << "Enter 5 numbers" << endl;
	int i = 0;
	cin >> num;
	while (i < 4) {
		tree.insert(num);
		cin >> num;
		i++;
	}

	cout << endl << "Tree nodes in inorder: " << endl;
	tree.inorderTraversal();
	cout << endl << "I'm going to add 3 to your tree" << endl;
	tree.insert(3);

	cout << endl << "Tree nodes in inorder: " << endl;
	tree.inorderTraversal();

	cout << endl << "Print tree in post-order, non recursively... " << endl;
	tree.postorderNonrecursive();
	cout << endl;
	
	cout << endl << "Print tree in pre-order, non recursively... " << endl;
	tree.preorderNonrecursive();
	cout << endl;

	cout << endl << "Print tree in-order, non recursively... " << endl;
	tree.inorderNonrecursive();
	cout << endl;

	cout << endl << "Tree Height: " << tree.treeHeight() << endl << endl;
	tree.isEmpty() == true ? cout << "our tree is empty" << endl : cout << "our tree is not empty." << endl;
	cout << endl << "destroying tree..." << endl;
	tree.destroyTree();
	tree.isEmpty() == true ? cout << "our tree is empty" << endl : cout << "our tree is not empty." << endl;


	system("pause");
	return 0;
}
