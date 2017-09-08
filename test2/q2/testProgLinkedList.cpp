//This program tests various operation of a linked list
//34 62 21 90 66 53 88 24 10 -999
  
#include <iostream>
#include "unorderedLinkedList.h"
 
using namespace std;

//prototypes
int recursiveGCD(int num1, int num2);
int nonrecursiveLCM(int num1, int num2);
int listLCM(unorderedLinkedList<int> list);

int main() {
    unorderedLinkedList<int> list;
    int num;
	cout << "Enter integers ending with -999" << endl;
    cin >> num;
    while (num != -999) {
        list.insertLast(num);
        cin >> num;
    }
    cout << endl;
	cout << "list: ";
    list.print();
    cout << endl;
    cout << "Length of list: " << list.length() << endl;

    cout << endl << "Output list using an iterator" << endl;
    linkedListIterator<int> it;

    for (it = list.begin(); it != list.end(); ++it)
        cout << *it << " ";
    cout << endl;

	cout << listLCM(list) << endl; ////////////////////////////////////////print the LCM of "n" numbers you entered.
	system("pause");

    return 0;
}

int listLCM(unorderedLinkedList<int> list) {
	cout << "Least Common Multiple: " << endl;
	linkedListIterator<int> lcmNums;
	int temp;				//temporary variable to store first item in list
	int lcm = 0;			//current least common multiple
	lcmNums = list.begin();	//set lcmNums to the beginning of "list"
	temp = *lcmNums;		//lcmNums = first list item, assign to temp
	++lcmNums;				//lcmNums = second list item.
	lcm = nonrecursiveLCM(temp, *lcmNums); 
							//lcm = least common multiple of first and second list item
	++lcmNums;				//lcmNums = third list item

	for (lcmNums; lcmNums != list.end(); ++lcmNums) { //lcmNums is now = third list item, and so forth until "end" of list
		lcm = nonrecursiveLCM(lcm, *lcmNums);	//assign lcm of all previous list items to "lcm"
	}
	return lcm; //return total least common multiple
}

//divide function calls recursively
//recursive GCD sends two numbers, and "num2" as the divisor to be subtracted from.
int divide(int num1, int num2, int divisor) {
	if ((num1 % divisor == 0) && (num2 % divisor == 0)) {
		return divisor;
	}
	else {
		divide(num1, num2, divisor - 1);
	}
}

//main function, calls divide function. divide calls itself recurisvely.
int recursiveGCD(int num1, int num2) {
	if (num1 < 0) {
		num1 *= -1;
	} if (num2 < 0) {
		num2 *= -1;
	} if (num1 == 0 || num2 == 0) {
		return 1;
	}
	//send two numbers and a divsor to subtract 1 from and caclulate modulus.
	return divide(num1, num2, num2);

}

//lcm calls recursive GCD with its parameters, then returns the formula.
int nonrecursiveLCM(int num1, int num2) {
	if (num1 < 0) {
		num1 *= -1;
	} if (num2 < 0) {
		num2 *= -1;
	}
	return (num1 * num2) / recursiveGCD(num1, num2);
}