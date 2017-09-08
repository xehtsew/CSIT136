//Header file: stackADT.h

#ifndef H_priorityQueue
#define H_priorityQueue
  
//*************************************************************
// Author: D.S. Malik
//
// This class specifies the basic operations on a queue.
//*************************************************************
#include "queueADT.h"
#include <cassert>
using namespace std;

template <class Type>
class priorityQueue: public queueADT<Type> {
public:
	bool isEmptyQueue() const;
	//Function to determine whether the queue is empty.
	//Postcondition: Returns true if the queue is empty,
	//    otherwise returns false.

	bool isFullQueue() const;
	//Function to determine whether the queue is full.
	//Postcondition: Returns true if the queue is full,
	//    otherwise returns false.

	void initializeQueue();
	//Function to initialize the queue to an empty state.
	//Postcondition: The queue is empty

	Type front() const;
	//Function to return the first element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: If the queue is empty, the program 
	//    terminates; otherwise, the first element of the
	//    queue is returned.  

	Type back() const;
	//Function to return the last element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: If the queue is empty, the program 
	//    terminates; otherwise, the last element of the queue
	//    is returned.

	void addQueue(const Type& queueElement);
	//Function to add queueElement to the queue.
	//Precondition: The queue exists and is not full.
	//Postcondition: The queue is changed and queueElement is
	//    added to the queue.

	void deleteQueue();
	//Function to remove the first element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: The queue is changed and the first element
	//    is removed from the queue.

	priorityQueue(int queueSize = 100);
	//Constructor

	~priorityQueue();
	//Destructor

private:
	void heapify(int low, int high);
	void buildHeap();

	int maxQueueSize; //variable to store the maximum queue size
	int count;        //variable to store the number of
					  //elements in the queue
	int queueFront;   //variable to point to the first
					  //element of the queue
	int queueRear;    //variable to point to the last
					  //element of the queue
	Type *list;       //pointer to the array that holds 
					  //the queue elements 
};


template <class Type>
bool priorityQueue<Type>::isEmptyQueue() const {
	return (count == 0);
} //end isEmptyQueue

template <class Type>
bool priorityQueue<Type>::isFullQueue() const {
	return (count == maxQueueSize);
} //end isFullQueue

template <class Type>
void priorityQueue<Type>::initializeQueue() {
	queueFront = 0;
	queueRear = maxQueueSize - 1;
	count = 0;
} //end initializeQueue

template <class Type>
Type priorityQueue<Type>::front() const {
	assert(!isEmptyQueue());
	return list[queueFront];
} //end front

template <class Type>
Type priorityQueue<Type>::back() const {
	assert(!isEmptyQueue());
	return list[queueRear];
} //end back

template <class Type>
void priorityQueue<Type>::addQueue(const Type& newElement) {
	if (!isFullQueue()) {
		queueRear = (queueRear + 1) % maxQueueSize; //use mod
													//operator to advance queueRear  
													//because the array is circular
		count++;
		list[queueRear] = newElement;
	}
	else
		cout << "Cannot add to a full queue." << endl;
	buildHeap();
} //end addQueue

template <class Type>
void priorityQueue<Type>::deleteQueue() {
	if (!isEmptyQueue()) {
		count--;
		queueFront = (queueFront + 1) % maxQueueSize; //use the
													  //mod operator to advance queueFront 
													  //because the array is circular 
	}
	else
		cout << "Cannot remove from an empty queue" << endl;
	buildHeap();
} //end deleteQueue

  //Constructor
template <class Type>
priorityQueue<Type>::priorityQueue(int queueSize)
{
	if (queueSize <= 0)
	{
		cout << "Size of the array to hold the queue must "
			<< "be positive." << endl;
		cout << "Creating an array of size 100." << endl;

		maxQueueSize = 100;
	}
	else
		maxQueueSize = queueSize;   //set maxQueueSize to 
									//queueSize

	queueFront = 0;                 //initialize queueFront
	queueRear = maxQueueSize - 1;   //initialize queueRear
	count = 0;
	list = new Type[maxQueueSize];  //create the array to
									//hold the queue elements
} //end constructor

  //Destructor
template <class Type>
priorityQueue<Type>::~priorityQueue() {
	delete[] list;
} //end destructor


template<class Type>
void priorityQueue<Type>::heapify(int low, int high)
{
	int largeIndex;
	Type temp = list[low]; //copy the root node of the subtree
	largeIndex = 2 * low + 1; //index of the left child
	while (largeIndex <= high)
	{
		if (largeIndex < high)
			if (list[largeIndex] < list[largeIndex + 1])
				largeIndex = largeIndex + 1; //index of the largest
											 //child
		if (temp > list[largeIndex]) //subtree is already in a heap
			break;
		else
		{
			list[low] = list[largeIndex]; //move the larger child
										  //to the root
			low = largeIndex; //go to the subtree to restore the heap
			largeIndex = 2 * low + 1;
		}
	}//end while
	list[low] = temp; //insert temp into the tree, that is, list
} //end heapify


template <class Type>
void priorityQueue<Type>::buildHeap() {
	for (int index = count / 2 - 1; index >= 0; index--)
		heapify(index, count - 1);
}
#endif