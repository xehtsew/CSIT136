//Write a program that takes as input an arithmetic expression.The program
//outputs whether the expression contains matching grouping symbols.For
//example, the arithmetic expressions{ 25 + (3 – 6) * 8 } and 7 + 8 * 2 contains
//matching grouping symbols.However, the expression 5 + {(13 + 7) / 8 - 2 * 9
//does not contain matching grouping symbols.

#include <iostream>
#include <string>
using namespace std;

int main() {
	int beginningParen = 0, endingParen = 0;
	int beginningCurly = 0, endingCurly = 0;
	int beginningBracket = 0, endingBracket = 0;

	string userInput;
	cout << "Enter an expression to find if it contains ";
	cout << "matching grouping symbols: " << endl;
	getline(cin, userInput);

	for (int i = 0; i < userInput.length(); i++) {
		switch (userInput[i]) {
		case '(':
			beginningParen++;
			break;
		case '[':
			beginningBracket++;
			break;
		case '{':
			beginningCurly++;
			break;
		case ')':
			endingParen++;
			break;
		case ']':
			endingBracket++;
			break;
		case '}':
			endingCurly++;
			break;
		}
	}

		if (beginningParen != endingParen) {
			cout << "Uneven Parentheses" << endl;
		} else if (beginningCurly != endingCurly) {
			cout << "Uneven Curly braces" << endl;
		} else if (beginningBracket != endingBracket) {
			cout << "Uneven Brackets" << endl;
		} else {
			cout << "Looks good" << endl;
		}


	system("pause");
	return 0;
}