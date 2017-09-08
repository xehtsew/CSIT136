#include "TheJarsProblem.h"
#include "Jar.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;
TheJarsProblem::TheJarsProblem() {
	jars.resize(4);
	jars[0].capacity = 24;
	jars[0].volume = 24;
	jars[1].capacity = 13;
	jars[1].volume = 0;
	jars[2].capacity = 11;
	jars[2].volume = 0;
	jars[3].capacity = 5;
	jars[3].volume = 0;
}

TheJarsProblem::TheJarsProblem(vector<Jar> vectorToCopy) {
	bool capacityGreaterThanZero = true;
	bool allJarsEmpty = true;
	for (int i = 0; i < vectorToCopy.size(); i++) {
		if (vectorToCopy[i].capacity < 0) {
			capacityGreaterThanZero = false;
		}
	} 
	for (int i = 1; i < vectorToCopy.size(); i++) {
		if (vectorToCopy[i].volume != 0) {
			allJarsEmpty = false;
		}
	}

	int gcd = 1;
	while (gcd == 1) {
		for (int i = 0; i < vectorToCopy.size(); i++) {
			for (int j = 0; j <= vectorToCopy[i].volume && j <= vectorToCopy[j].volume; j++) {
				if (vectorToCopy[i].volume%j == 0 && vectorToCopy[j].volume%j == 0) {
					gcd = j;
				}
			}
		}
	}
	
	if (capacityGreaterThanZero != true) {
		cout << "All jars' capacity must be larger than 0" << endl;
	} else if (allJarsEmpty != true) {
		cout << "All jars except the first must be empty" << endl;
	} else if (gcd != 1) {
		cout << "The GCD of all jars must equal 1" << endl;
	} else if (vectorToCopy[1].volume != 0 && vectorToCopy[2].volume != 0 && vectorToCopy[3].volume != 0) {
		cout << "All jars except first must be empty" << endl;
	} else if (vectorToCopy.size() < 3) {
		cout << "Not enough jars" << endl;
	} else if (vectorToCopy[0].volume != vectorToCopy[0].capacity){
		cout << "The largest capacity jar's volume must equal its capacity (be full)" << endl;
	} else if ((vectorToCopy.size() - 1) % vectorToCopy[0].capacity != 0) {
		cout << "The number of jars less 1 must divide the largest capacity jar evenly" << endl;
	} else {
		jars = vectorToCopy;
	}
}

TheJarsProblem::~TheJarsProblem() {
}
void TheJarsProblem::divide() {
	int count = 0;
	do {
		int source, destination;
		read(source, destination);
		pour(source, destination);
		count++;
		show(count);
	} while (jars[0].volume != 8 || jars[1].volume != 8 || jars[2].volume != 8);
	//until volumes of originally empty jars are equal   
	cout << "Congratulations!" << endl;
} 
void TheJarsProblem::read(int& source, int& destination){
		cout << "Source? ";
		cin >> source;
		cout << "Jar " << source << " is the source" << endl;
		cout << "Destination? ";
		cin >> destination;
		cout << "Jar " << destination << " is the destination" << endl;
		if (source > jars.size() || destination > jars.size() || source < 0 || destination < 0) {
			cout << "Jar out of range. Try again" << endl;
			read(source, destination);
		}
}

void TheJarsProblem::pour(int source, int destination) {
	if (source == destination) {
		cout << "No self pours" << endl;
	} else {
		while (jars[source].volume != 0 && jars[destination].volume != jars[destination].capacity) {
			jars[source].volume--;
			jars[destination].volume++;
		}
	}
}

void TheJarsProblem::show(int count) {
	cout << count << ": ";
	for (int index = 0; index <= 3; index++)
		cout << jars[index].volume << ' ';
	cout << endl;
}