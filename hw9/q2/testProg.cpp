#include <iostream>
#include "orderedArrayListType.h"
#include "arrayListType.h"

using namespace std;

int main() {	
	//Write a program to test quicksort for array-based lists as given in this chapter.
	arrayListType<int> a;
	//set of random numbers for array...from book
	a.insert(32); a.insert(55); a.insert(87); a.insert(13);
	a.insert(78); a.insert(96); a.insert(52); a.insert(48);
	a.insert(22); a.insert(11); a.insert(58); a.insert(66); a.insert(45);

	cout << "Before sorting: " << endl;
	a.print(); //print unsorted list
	a.quickSort(); //sort list
	cout << "After sorting: " << endl;
	a.print(); // print sorted list
	system("pause");
	return 0;
}
