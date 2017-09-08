#include <iostream>
#include <string>
using namespace std;
string encode(string input);
string decode(string input);
string alphaSqueeze(string input);
string digitSqueeze(string input);

char matrix[5][5] =
{ {'A','B','C','D','E'},
  {'F','G','H','I','J'},
  {'K','L','M','N','O'},
  {'P','Q','R','S','T'},
  {'U','V','W','X','Y/Z'} };

int main() {

	string userInput;
	string programOutput;
	//test if user input is only numbers, only alpha, or let the user select
	//alpha squeeze or digit squeeze, cout the result, and automatically call the correct function

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
		string sqozenInput;
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
			string squozenInput = alphaSqueeze(userInput);
			cout << "Squeeze result : " << squozenInput << endl << endl << "   ENCODING..." << endl;
			programOutput = encode(squozenInput);
		} else  { //continu == 2
			cout << "Squeezing the letters from your input..." << endl;
			string squozenInput = digitSqueeze(userInput);
			cout << "Squeeze result : " << squozenInput << endl << endl << "   DECODING..." << endl;
			programOutput = decode(squozenInput);
		}

	} else if (isAllAlpha == true) {
		cout << "   ENCODING... " << endl;
		programOutput = encode(userInput);
	} else {
		cout << "   DECODING... " << endl;
		programOutput = decode(userInput);
	}

	cout << endl << endl << endl << "Results: " << endl;
	cout << programOutput << endl << endl;
	 
	system("pause");
	return 0;
}

string encode(string input) {
	string output;
	for (int i = 0; i < input.length(); i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				if (toupper(input[i]) == matrix[j][k]) {
					cout << matrix[j][k];
					output += (j + 1) + '0';
					output += (k + 1) + '0';
				}
			}
		}
	}
	return output;
}


string decode(string input) {
	string output;
	if (input.length() % 2 != 0) {
		cout << "That doesnt seem to be a valid cipher code... "
			<< endl << "input an even number of numbers only." << endl;
		return "error!";
	} else {
		int row;
		int column;
		int counter = 0;
		while (counter < input.length()) {
			row = input[counter] - '0';
			counter++;
			column = input[counter] - '0';
			counter++;
			output += matrix[row - 1][column - 1];
		}
	}

	return output;
}

string alphaSqueeze(string input) {
	string output;
	for (int n = 0; n < input.length(); n++) {
		if (isalpha(input[n])) {
			output += toupper(input[n]);
		}
	}
	return output;
}

string digitSqueeze(string input) {
	string output;
	for (int n = 0; n < input.length(); n++) {
		if (isdigit(input[n])) {
			output += input[n];
		}
	}
	return output;
}