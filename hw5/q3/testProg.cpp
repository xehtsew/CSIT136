#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string userInput, int position, int length) {
	if (position == userInput.length() && length == 0) {
		return true;
	}
	else if (userInput[position] != userInput[length - 1]) {
		return false;
	}
	else {
		return isPalindrome(userInput, position + 1, length - 1);
	}
}

int main() {
	string userInput;
	cout << "Enter a palindrome to check: " << endl;
	getline(cin, userInput);

	if (isPalindrome(userInput, 0, userInput.length()) == true) {
		cout << "is a palindrome" << endl;
	} 	else {
		cout << "not a palindrome" << endl;
	}


	system("pause");
	return 0;
}