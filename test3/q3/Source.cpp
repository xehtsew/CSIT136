#include <iostream>
#include <string>
#include <vector>
#include "TheJarsProblem.h"
using namespace std;

/*
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

int main() {
	TheJarsProblem jarVector;
	int count = 0;
	jarVector.show(count);
	jarVector.divide();

	TheJarsProblem newJarVector;
	TheJarsProblem jarVectorToCopy(newJarVector);
	int counter = 0;
	jarVectorToCopy.show(counter);
	jarVectorToCopy.divide();

	system("pause");
	return 0;
}