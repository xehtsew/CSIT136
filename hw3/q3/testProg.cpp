//****************************************************************
// Author: D.S. Malik
//
// This program illustrates how to use the class arrayListType.
//****************************************************************
 
#include <iostream>

#include <string>
#include "safeArray.h"

using namespace std;

int main() {
	
	safeArray sa(16);

	sa.insertEnd(8);
	sa.insertEnd(3);
	sa.insertEnd(11);
	sa.insertAt(0, 6);//[6,8,3,11]
	sa.print();

	cout << sa.seqSearch(11) << endl;

	cout << endl << endl;

	safeArray sa2(-5, 16);
	sa2.insertEnd(8);   // [8]
	sa2.insertEnd(8);
	sa2.insertEnd(3);   //[8,8,3]
	sa2.insertEnd(11);  //[8,8,3,11]
	sa2.insertAt(-5, 6);//[6,8,8,3,11]

	sa2.print();

	cout << sa2.seqSearch(11) << endl;
	//returns location as if 0 was the original start index

	system("pause");




    return 0;
}

