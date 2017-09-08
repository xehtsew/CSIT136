/*
9. Using classes, design an online address book to keep track of the names,
addresses, phone numbers, and dates of birth of family members, close friends,
and certain business associates.Your program should be able to handle a
maximum of 500 entries.
	a.Define a class, addressType, that can store a street address, city, state,
		and zip code.Use the appropriate functions to print and store the address.
		Also, use constructors to automatically initialize the data members.
	b.Define a class extPersonType using the class personType(as defined
		in Example 1 - 12, Chapter 1), the class dateType(as designed in Programming
		Exercise 2 of Chapter 2), and the class addressType.Add a
		data member to this class to classify the person as a family member, friend,
		or business associate.Also, add a data member to store the phone number.
		Add(or override) the functions to print and store the appropriate information.
		Use constructors to automatically initialize the data members.
	c.Derive the class addressBookType from the class arrayListType, as
		defined in this chapter, so that an object of type addressBookType can store
		objects of type extPersonType.An object of type addressBookType
		should be able to process a maximum of 500 entries.Add necessary operations
		to the class addressBookType so that the program should perform
		the following operations :
			i.Load the data into the address book from a disk.
			ii.Search for a person by last name.
			iii.Print the address, phone number, and date of birth(if it exists) of a
				given person.
			iv.Print the names of the people whose birthdays are in a given month
				or between two given dates.
			v.Print the names of all the people having the same status, such as
				family, friend, or business.
			vi.Print the names of all the people between two last names.
//////////part 2/////////
1. (Online Address Book Revisited) Programming Exercise 9 in Chapter 3 could
	handle a maximum of only 500 entries. Using linked lists, redo the program to
	handle as many entries as required. Add the following operations to your program:
	a. Add or delete a new entry to the address book.
	b. When the program terminates, write the data in the address book to a disk.
*/

#include <iostream>
#include <fstream> // for files
#include <string>
#include "addressBookType.h"
using namespace std;

void menu();
int main() {
	addressBookType addressBook;
	//load address book
	addressBook.load(addressBook);
	
	//extPersonType p;
	//dateType birthday;
	//birthday.setDate(10, 10, 1999);
	//extPersonType q;
	//q.setExtPerson("Andy", "Wyman", "323-323-3233", birthday, FAMILY);
	//q.setAddress("123 Fake St", "Hollywood", "CA", "90210");
	//addressBook.insertAt(0, q);
	//addressBook.insertAt(1, p);

	string choice = " ";
	
	while (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" &&
		choice != "6" && choice != "7" && choice != "8") {
		menu();
		cout << endl;
		getline(cin, choice);
		
		if (choice == "1") {
			system("cls");
			string lastNameToFind;
			extPersonType personToFind;
			cout << "Find a person by last name (cAsE sEnSiTiVe!): " << endl;
			getline(cin, lastNameToFind);
			personToFind.setLastName(lastNameToFind);
			addressBook.print(personToFind);
			
			system("pause");
		choice = " ";
	} else if(choice == "2") {
		int birthdayMonth = 100;
		while (birthdayMonth > 12 || birthdayMonth < 0) {
			system("cls");
			cout << "Print all birthdays within a given month: " << endl;
			cout << "Use numbers (ex. Jan = 1, Feb = 2... Dec = 12) ONLY" << endl;
			cin >> birthdayMonth;
			cin.ignore();
			cin.clear();
			dateType date;
			date.setMonth(birthdayMonth);
			addressBook.print(date, date);
		}
		
		system("pause");
		choice = " ";
	} else if (choice == "3") {
		char choix = ' ';
		while (choix != '1' && choix != '2' && choix != '3' && choix != '4' && choix != '5') {
			system("cls");
			cout << "Print entries with a relationship of:" << endl
				<< "1. Family" << endl << "2. Friend" << endl << "3. Business" 
				<< endl << "4. Other" << endl << "5. Exit" << endl << endl;
			cin.get(choix);
			if (choix == '1') {
			addressBook.print(FAMILY);
			}else if (choix == '2') {
			addressBook.print(FRIEND);
			}else if (choix == '3') {
			addressBook.print(BUSINESS);
			}else if (choix == '4') {
			addressBook.print(OTHER);
			}
		}		
		system("pause");
		choice = " ";
	} else if (choice == "4") {
		string name1;
		string name2;
		system("cls");
		cout << "Print all entries with last names alphabetically between two names" << endl;
		cout << "Name 1: " << endl;
		getline(cin, name1);
		cout << "Name 2: " << endl;
		getline(cin, name2);
		addressBook.print(name1, name2);
		system("pause");
		choice = " ";
	} else if (choice == "5") {
		addressBook.insertEnd(addressBook.addEntry());
		system("pause");
		choice = " ";
	} else if (choice == "6") {
		addressBook.deleteEntry(addressBook);

		system("pause");
		choice = " ";
	} else if (choice == "7") {
		addressBook.print();
		system("pause");
		choice = " ";
	}


}
	string save;
	cout << "Save Address Book? y/Y" << endl;
	getline(cin, save);
	if (save == "y" || save == "Y")
		addressBook.save(addressBook);
	system("pause");
	return 0;
}

void menu() {
	system("cls");
	cout << "Address Book" << endl << endl;
	cout << "Menu: " << endl << "1. Search By Last Name" << endl
		<< "2. Print Those with a birthday in given month" << endl
		<< "3. Print friends, family, business or other" << endl
		<< "4. Print between two last names" << endl
		<< "5. Add a new entry" << endl
		<< "6. Delete an entry" << endl
		<< "7. Print entire address book" << endl
		<< "8. Exit" << endl;
}