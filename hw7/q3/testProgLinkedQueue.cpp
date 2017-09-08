//***************************************************************
// Author: D.S. Malik
//
// This program illustrates how to use the class linkedQueueType
// in a program.
//***************************************************************
#include <iostream>
#include "linkedQueue.h"
using namespace std;
int main()
{
	linkedQueueType<int> queue;
	cout << "Creating original Queue... adding integers" << endl;
	int x, y;
	queue.initializeQueue();
	x = 4;
	y = 5;
	queue.addQueue(x);
	queue.addQueue(y);
	x = queue.front();
	queue.deleteQueue();
	queue.addQueue(x + 5);
	queue.addQueue(16);
	queue.addQueue(x);
	queue.addQueue(y - 3);
	cout << "Creating 2 new queues..." << endl;
	linkedQueueType<int> queueCopyWithEquals;
	cout << "Copying old queue to queueCopyWithCopyConstructor with copy constructor" << endl;

	linkedQueueType<int> queueCopyWithCopyConstructor(queue);
	cout << "Copying old queue to queueCopyWithEquals with \"=\"" << endl;
	queueCopyWithEquals = queue;

	cout << endl << endl;
	cout << "Original Queue Elements: ";
	while (!queue.isEmptyQueue()) {
		cout << queue.front() << " ";
		queue.deleteQueue();
	}
	cout << endl << endl;
	cout << "queueCopyWithEquals Queue Elements: ";
	while (!queueCopyWithEquals.isEmptyQueue()) {
		cout << queueCopyWithEquals.front() << " ";
		queueCopyWithEquals.deleteQueue();
	}
	cout << endl << endl;
	cout << "queueCopyWithCopyConstructor Queue Elements: ";
	while (!queueCopyWithCopyConstructor.isEmptyQueue()) {
		cout << queueCopyWithCopyConstructor.front() << " ";
		queueCopyWithCopyConstructor.deleteQueue();
	}
	cout << endl << endl;

	system("pause");
	return 0;
}