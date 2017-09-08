#include<iostream>
#include<queue>
#include<stack>
#include<string>
using namespace std;
bool isPalindrome(string userInput, int position, int length);

//Write a program that reads a line of text, changes each uppercase letter to
//lowercase, and places each letter both in a queue and onto a stack.The
//program should then verify whether the line of text is a palindrome(a set of
//letters or numbers that is the same whether read forward or backward).

int main() {
	queue<char> wordQ;
	stack<char> wordStack;
	string userInput;
	cout << "Enter a string to place it onto a queue and into a stack: " << endl;
	getline(cin, userInput);

	for (int i = 0; i < userInput.length(); i++) {
		if (isupper(userInput[i])) {
			tolower(userInput[i]);
		} else if (islower(userInput[i])){
			toupper(userInput[i]);
		}
		wordQ.push(userInput[i]);
		wordStack.push(userInput[i]);
	}
	cout << "All letters are in a queue and on a stack" << endl;
	cout << "The legnth of the user's input is: " << userInput.length() << endl;
	cout << "The queue's size is: " << wordQ.size() << endl;
	cout << "The stack's size is: " << wordStack.size() << endl;

	if (isPalindrome(userInput, 0, userInput.length()) == true) {
		cout << "This is a palindrome" << endl;
	}
	else {
		cout << "This is not a palindrome" << endl;
	}


	system("pause");
	return 0;
}

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