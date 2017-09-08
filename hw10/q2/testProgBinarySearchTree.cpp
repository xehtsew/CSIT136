#include "binaryTree.h"
#include <iostream>

using namespace std;

int main() {
	//I added the "insert" function from another .h file to add items
	//to my tree, and then demonstrated the nodecount, treeheight
	//and singleparent function we were asked to write


	binaryTreeType<int> b;

	b.insert(10);
	b.insert(8);
	b.insert(6);
	b.insert(4);
	b.insert(2);
	b.insert(1);
	b.insert(3);
	b.insert(5);
	b.insert(7);
	b.insert(9);

	cout << "Tree node count: " << endl;
	cout  << b.treeNodeCount() << endl << endl;

	cout << "Tree Height: " << endl;
	cout  << b.treeHeight() << endl << endl;

	cout << "Single Parent Count: " << endl;
	cout  << b.singleParentCount() << endl << endl;


	system("pause");

    return 0;
}