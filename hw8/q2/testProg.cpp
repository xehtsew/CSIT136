
#include <iostream>

#include "orderedArrayListType.h"

using namespace std;

int main()
{
	orderedArrayListType<int> a;
	int orderedNumbers[] = { 10,20,30,40,50 };
	//add ordered numbers into a list from preexistng ordered array for time's sake
	for (int counter = 0; counter < 5; counter++){
		a.insertAt(counter, orderedNumbers[counter]);
	}
	cout << "Heres your ordered list: " << endl;
	a.print();
	int number;
	cout << "enter a number to add to your list: " << endl;
	cin >> number;
	a.insertOrd(number);
	cout << "Heres your list now: " << endl;
	a.print();

	system("pause");
	return 0;
}
