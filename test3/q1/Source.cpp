/*
The Problem
Three women robbed a gentleman of a vase, containing 24 ounces 
of balsam. Whilst running away they met a glass-seller, of 
whom they purchased three vessels. On reaching a place of 
safety they wished to divide the booty, but fond that their 
vessels contained 5, 11, and 13 ounces respectively. How could 
they divide the balsam into equal portions?

solution:
0.			24  0  0 0
1.	0-1		11 13  0 0
2.	0-3		6  13  0 5
3.	1-2		6   2 11 5
4.	1-0		8   0 11 5
5.	3-1		8   5 11 0
6.	2-1		8  13  3 0
7.	1-3		8   8  3 5
8.	3-2		8   8  8 0
*/

#include <iostream>
#include <string>
using namespace std;

const int TUB = 0;
const int JAR1 = 1;
const int JAR2 = 2;
const int JAR3 = 3;

const int capacity[] = {24, 13, 11, 5};
const string names[] = {"Tub", "Jar 1", "Jar 2", "Jar 3"};
int volume[] = {24, 0, 0, 0};

void display(int count);
void read(int& source, int& destination);
void pour(int source, int destination);
bool isEmpty(int container);
bool isFull(int container);

int main() {
	int count = 0;
	display(count);

	do {
		int source, destination;
		read(source, destination);
		pour(source, destination);
		count++;
		display(count);
	}
	while((volume[JAR1] != 8) || (volume[JAR2] != 8) || (volume[TUB] != 8));

	system("pause");
	return 0;
}
void pour(int source, int destination) {
	while(!isEmpty(source) && !isFull(destination)) {
		volume[source]--;
		volume[destination]++;
	}
}
bool isEmpty(int container) {
	return volume[container] == 0;
}
bool isFull(int container) {
	return volume[container] == capacity[container];
}
void read(int& source, int& destination) {
	cout << "source? ";
	cin >> source;
	cout << names[source] << " is the source" << endl;
	cout << "destination? ";
	cin >> destination;
	cout << names[destination] << " is the destination" << endl;
}
void display(int count) {
	cout << count << ": ";
	for(int index = TUB; index <= JAR3; index++)
		cout << volume[index] << ' ';
	cout << endl;
}