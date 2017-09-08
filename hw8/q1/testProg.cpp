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
    arrayListType<string> stringList;                     //Line 8
    string str;                                           //Line 26
    cout << "Line 27: Enter 5 strings: ";                 //Line 27
    for (int counter = 0; counter < 5; counter++)         //Line 28
    {                                                     //Line 29
        cin >> str;                                       //Line 30
        stringList.insertAt(counter, str);                //Line 31
    }                                                     //Line 32

    cout << endl;                                         //Line 33
    cout << "Line 34: The list you entered is: " << endl; //Line 34
    stringList.print();                                   //Line 35
    cout << endl;                                         //Line 36
	//////////////////////////////////////////////////////////////////////////
	cout << "This is the recursive search. Enter string to find" << endl;
	string stringToFind;
	cin >> stringToFind;

	cout << "Location of your item: " << endl;
	cout << "Location: " << stringList.recursiveSeqSearch(stringToFind);
	cout << endl;
	//////////////////////////////////////////////////////////////////////////

	system("pause");
    return 0;                                             //Line 43
}                                                         //Line 44

