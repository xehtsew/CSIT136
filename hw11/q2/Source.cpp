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
		cout << endl << "I'm going to try to add 2 more numbers... 3 and 3:" << endl;
		//displays error
		tree.insert(3);
		tree.insert(3);

		cout << endl << "Tree nodes in inorder: " << endl;
		tree.inorderTraversal();

		cout << endl << "is 3 in our tree? searching..." << endl << endl;
		tree.search(3) == true ? cout << "3 is in our tree" : cout << "3 is not in our tree" << endl;

		cout << endl << "now, lets delete that 3." << endl;
		tree.deleteNode(3);

		cout << endl << "display the nodes again.. without 3!" << endl;
		tree.inorderTraversal();

		cout << endl << "Tree Height: " << tree.treeHeight() << endl << endl;
		tree.isEmpty() == true ? cout << "our tree is empty" << endl : cout << "our tree is not empty." << endl;
		cout << endl << "destroying tree..." << endl;
		tree.destroyTree();
		tree.isEmpty() == true ? cout << "our tree is empty" << endl : cout << "our tree is not empty." << endl;


	system("pause");
	return 0;
}
