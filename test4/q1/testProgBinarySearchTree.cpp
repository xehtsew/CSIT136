/*Add two functions to a binary tree class. The first function returns an array 
list or vector. It is modified version of the public in order tree traversal 
function. The first function invokes the second function, a modified version of 
the private in order tree traversal function.The second function copies the 
tree nodes' data  to the array list or vector as it visits each node.
Write a program to test your function.
*/

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
	do {		
		cin >> num;
		tree.insert(num);
		i++;
	} while (i < 5);

	cout << endl << endl << "Tree nodes in inorder: " << endl;
	tree.inorderTraversal();
	//////////////////////////////////////////////////////////////////////////////////////////////
	cout << endl << endl << "Copying tree nodes to a vector... " << endl;
	tree.inorderVectorTraversal();
	cout << "Done!" << endl << "Printing size of the vector: " << endl;
	cout << tree.dataVector.size();
	//////////////////////////////////////////////////////////////////////////////////////////////

	cout << endl << endl << "I'm going to try to add 2 more numbers... 3 and 3:" << endl;
	//displays error
	tree.insert(3);
	tree.insert(3);



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
