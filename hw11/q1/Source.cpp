/*
12. a. Write the definition of the class template to define the priority queues,
as discussed in this chapter as an abstract data type(ADT).

	b. Write the definitions of the function templates to implement the
operations of the priority queues as defined in part(a).
	
	c. Write a program to test various operations of the priority queues.
*/

#include <iostream>
#include "priorityQueue.h"
using namespace std;

int main() {

	priorityQueue<int> q;
	q.initializeQueue();

	if (q.isEmptyQueue() == 1) {
		cout << "queue is empty!" << endl;
	}else {
		cout << "queue is not empty!" << endl;
	}


	if (q.isFullQueue() == 0) {
		cout << "queue is not full!" << endl;
	}
	else {
		cout << "queue is full!" << endl;
	}

	cout << "adding 50 to queue..." << endl;
	q.addQueue(50);
	cout << "printing front of queue..." << endl;
	cout << q.front() << endl;
	cout << "adding 51 to queue..." << endl;
	q.addQueue(51);
	cout << "printing front of queue..." << endl;
	cout << q.front() << endl;



	cout << "adding 88" << endl;
	q.addQueue(88);
	cout << "printing front" << endl;
	cout << q.front() << endl;

	cout << "adding 7" << endl;
	q.addQueue(7);
	cout << "printing" << endl;
	cout << q.front() << endl;

	cout << "adding 67" << endl;
	q.addQueue(67);
	cout << "printing" << endl;
	cout << q.front() << endl;

	cout << "adding 104" << endl;
	q.addQueue(104);
	cout << "printing" << endl;
	cout << q.front() << endl;

	if (q.isEmptyQueue() == 1) {
		cout << "queue is empty!" << endl;
	}
	else {
		cout << "queue is not empty!" << endl;
	}



	system("pause");
	return 0 ;
}