#include <iostream>
#include "personType.h"
using namespace std;

int main() {
	//define class member as p
	personType p;
	//define input buffer
	char userInput[200];

	//get first name, get user input, set first name
	cout << "What is the first name of the person?" << endl;
	cin.getline(userInput, 256);
	p.setFirstName(userInput);
	//get middle name, get user input, set middle name
	cout << "\nWhat is the middle name of the person?" << endl;
	cin.getline(userInput, 256);
	p.setMiddleName(userInput);
	//get last name, get user input, set last name
	cout << "\nWhat is the last name of the person?" << endl;
	cin.getline(userInput, 256);
	p.setLastName(userInput);
	//msg to user calling 3 get statements
	cout << endl << "You entered: " << p.getFirstName() << " " << p.getMiddleName() << " " << p.getLastName() << endl;
	
	//msg to user to check names.. get users input for first name
	cout << endl << "OK... check his FIRST name again. Type it exactly the same please : " << endl;
	cin.getline(userInput, 256);
	//compare strings - case sensitive
	if (p.checkFirstName(userInput) == false) {
		cout << endl << "hmm... we have something different... try again later..." << endl;
		return 0;
	} else {
		cout << endl << " OK, great!" << endl;
	}
	//msg to user to get last name
	cout << "OK... lets check his last name now... \njust to be sure we're talking about the same person" << endl;
	cin.getline(userInput, 256);
	//compare strings - case sensitive
	if (p.checkLastName(userInput) == false) {
		cout << endl << "hmm... we have something different... try again later..." << endl;
		system("pause");
		return 0;
	} else {
		cout << endl << "OK, great!" << endl;
	}
	//msg to user and break
	cout << "Awesome. The names match!" << endl;
	system("pause");
	return 0;
}