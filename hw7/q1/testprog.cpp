#include <iostream>
using namespace std;

void recursionFunction(int longestLine, char c) {
		if (longestLine == 0) {
			return;
		} else {
			for (int index = 0; index < longestLine; index++) {
				cout << c;
			}
			cout << endl;
			recursionFunction(longestLine - 1, c);
			for (int index = 0; index < longestLine; index++) {
				cout << c;
			}
			cout << endl;
		}
	}

int main() {
	recursionFunction(4, '*');
	cout << endl << endl;
	system("pause");
	return 0;
}


