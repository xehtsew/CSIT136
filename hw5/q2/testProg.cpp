#include <iostream>
#include <string>
using namespace std;

int vowels(string userString, int count, int position) {
	if (position == userString.length() || userString.length() == 0) {
		return count;
	}
	else {
		switch (toupper(userString[position])) {
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			count++;
		}
		return vowels(userString, count, position + 1);
	}
}

int main() {
	string userString;
	cout << "Enter a string to count vowels: " << endl;
	getline(cin, userString);
	cout << "Your string has " << vowels(userString, 0, 0) << " vowels" << endl;
	system("pause");
	return 0;
}