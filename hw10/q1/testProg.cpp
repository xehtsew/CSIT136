#include <iostream>
#include "hashT.h"

using namespace std;

int main() {
	hashT<int> h;
	cout << "print hash table before insertion: " << endl;
	h.print();
	cout << endl <<endl;
	h.insert(0, 4);
	h.insert(0, 5);
	h.insert(0, 6);
	h.insert(0, 7);
	h.insert(0, 8);
	h.insert(0, 9);
	h.insert(0, 0);

	h.print();

	cout << endl << "is index 0 the number 4?" << endl;
	
	h.isItemAtEqual(0, 4) ? cout << "true" << endl : cout << "false" << endl;

	cout << "is index 7 the number 5?" << endl;
	h.isItemAtEqual(7, 5) ? cout << "true" <<endl : cout << "false" << endl;

	cout << endl << "Attempting to remove 4" << endl;
	h.remove(0, 4);
	cout << "Attempting to remove 3" << endl;
	h.remove(0, 3);
	cout << endl << endl;
	h.print();

	cout << endl;

	system("pause");
	return 0;
}