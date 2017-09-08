//****************************************************************
// Author: D.S. Malik
//
// This program illustrates how to use the class arrayListType.
//****************************************************************
 
#include <iostream>                                       //Line 1

#include <string>                                         //Line 2
#include "arrayListType.h"                                //Line 3

using namespace std;                                      //Line 4

int main()                                                //Line 5
{                                                         //Line 6
    arrayListType<int> intList(100);                      //Line 7
    arrayListType<string> stringList;                     //Line 8

	int number;                                           //Line 9
    cout << "List 10: Enter 5 integers: ";                //Line 10
    for (int counter = 0; counter < 5; counter++)         //Line 11
    {                                                     //Line 12
        cin >> number;                                    //Line 13
        intList.insertAt(counter, number);                //Line 14
    }                                                     //Line 15

    cout << endl;                                         //Line 16
    cout<<"List 19: The list you entered is: ";           //Line 17
    intList.print();                                      //Line 18
    cout << endl;                                         //Line 19

	int removeLocation;
	cout << "Enter a location to remove: " << endl;
	cin >> removeLocation;
	intList.removeAt(removeLocation);

	cout << "This is your list now" << endl;
	intList.print();

	system("pause");
    return 0;                                             //Line 43
}                                                         //Line 44

