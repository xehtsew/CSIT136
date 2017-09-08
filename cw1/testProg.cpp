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
	sa.insertEnd(12);
	sa.insertEnd(13);
	sa.insertAt(5, 6);
	sa.print();

	cout << sa.seqSearch(12) << endl;

	safeArray sa2(-5, 16);
	sa2.insertEnd(8);
	sa2.insertEnd(8);
	sa2.insertEnd(8);
	sa2.insertEnd(8);
	sa2.insertEnd(8);
	sa2.insertEnd(8);
	sa2.insertEnd(8);
	sa2.insertEnd(8);
	sa2.insertEnd(8);
	sa2.insertEnd(3);
	sa2.insertEnd(11);
	sa2.insertAt(-5, 6);

	sa2.print();

	cout << sa2.seqSearch(6) << endl;

	system("pause");




    return 0;
}

