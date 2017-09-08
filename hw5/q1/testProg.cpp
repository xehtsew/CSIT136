#include <iostream>
using namespace std;


void recursionFunction(int starting, int longestLine, char c) {

	for (int index = 0; index < starting; index++) {
		cout << c;
	}
	cout << endl;
	starting += 1;

	if (starting <= longestLine) {
		recursionFunction(starting, longestLine, c);
	}
	for (int index = 0; index < starting; index++) {
		cout << c;
	}
	cout << endl;

}

int main() {
	int stars;
	cout << "Enter the number of rows of stars you want: " << endl;
	cin >> stars;
	recursionFunction(0, stars, '*');
	cout << endl << endl;
	system("pause");
	return 0;
}