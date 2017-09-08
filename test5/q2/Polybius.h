#pragma once

#include <iostream>
#include <string>
using namespace std;


class Polybius {
public:
	Polybius();
	~Polybius();
	string encode(string input);
	string decode(string input);

private:
	string alphaSqueeze(string input);
	string digitSqueeze(string input);
	char matrix[5][5] =
	{ { 'A','B','C','D','E' },
	{ 'F','G','H','I','J' },
	{ 'K','L','M','N','O' },
	{ 'P','Q','R','S','T' },
	{ 'U','V','W','X','Y' } };

};

Polybius::Polybius() {
}
Polybius::~Polybius() {
}
string Polybius::encode(string input) {
	string squozenInput;
	for (int i = 0; i < input.length(); i++) {
		if (isdigit(input[i])) {
			squozenInput = alphaSqueeze(input);
			input = squozenInput;
			break;
		}
	}
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
string Polybius::decode(string input) {
	string squozenInput;
	for (int i = 0; i < input.length(); i++) {
		if (isalpha(input[i])) {
			squozenInput = digitSqueeze(input);
			input = squozenInput;
			break;
		}
	}

	string output;
	if (input.length() % 2 != 0) {
		cout << "That doesnt seem to be a valid cipher code... "
			<< endl << "input an even number of numbers only." << endl;
		return "error!";
	}
	else {
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
string Polybius::alphaSqueeze(string input) {
	string output;
	for (int n = 0; n < input.length(); n++) {
		if (isalpha(input[n])) {
			output += toupper(input[n]);
		}
	}
	return output;
}
string Polybius::digitSqueeze(string input) {

	string output;
	for (int n = 0; n < input.length(); n++) {
		if (isdigit(input[n])) {
			output += input[n];
		}
	}
	return output;
}