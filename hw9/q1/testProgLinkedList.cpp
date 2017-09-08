#include <iostream>
#include "unorderedLinkedList.h"
 
using namespace std;

int main() {
	//1. Write and test a version of selection sort for linked lists.
	unorderedLinkedList<int> list1;
	int num;

	cout << "Enter integers ending " << "with -999" << endl;
	cin >> num;

	while (num != -999) {
		list1.insertLast(num);
		cin >> num;
	}
	cout << endl;
	cout << "list1: ";
	list1.print();
	cout << endl;
	cout << "Length of list1: " << list1.length() << endl;
	cout << endl << "Output unsorted list1 " << endl;
	linkedListIterator<int> it;
	for (it = list1.begin(); it != list1.end(); ++it) {
		cout << *it << " ";
	}

	list1.selectionSort();
	cout << endl << endl << "Output sorted list1 " << endl;

	for (it = list1.begin(); it != list1.end(); ++it) {
		cout << *it << " ";
	}

    cout << endl;
	system("pause");
    return 0;
}

