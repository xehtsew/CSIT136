#include <iostream>
#include <string>
#include "Polybius.h"
using namespace std;


int main() {
	Polybius p;
	string userInput;
	string programOutput;
	cout << "Polybius Cipher" << endl;
	cout << "Enter a cipher to encode or decode" << endl;
	getline(cin, userInput);
	bool isAllAlpha = true;
	bool isAllDigit = true;

	for (int x = 0; x < userInput.length(); x++) {
		if (isalpha(userInput[x])) {
			isAllDigit = false;
		} else if (isdigit(userInput[x])) {
			isAllAlpha = false;
		} else {
			cout << "Letters and Numbers ONLY please..." << endl;
			system("pause");
			return 0;
		}
	}
	if (isAllAlpha == false && isAllDigit == false) {
		string continu = " ";
		//mixed case
		cout << "I want to use :" << endl << "1.Letters" << endl << "2.Numbers" << endl << endl;
		cout << "Make a selection" << endl;
		getline(cin, continu);
		while (continu != "1" && continu != "2") {
			cout << "invalid selection" << endl;
			getline(cin, continu);
		}
		if (continu == "1") {
			cout << "Squeezing the digits from your input..." << endl;
			cout << "   ENCODING..." << endl;
			programOutput = p.encode(userInput);
		} else  { //continu == 2
			cout << "Squeezing the letters from your input..." << endl;
			cout << "   DECODING..." << endl;
			programOutput = p.decode(userInput);
		}

	} else if (isAllAlpha == true) {
		cout << "   ENCODING... " << endl;
		programOutput = p.encode(userInput);
	} else {
		cout << "   DECODING... " << endl;
		programOutput = p.decode(userInput);
	}

	cout << endl << endl << endl << "Results: " << endl;
	cout << programOutput << endl << endl;
	 
	system("pause");
	return 0;
}
