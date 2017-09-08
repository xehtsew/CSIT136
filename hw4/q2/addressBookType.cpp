/*
i.Load the data into the address book from a disk.
ii.Search for a person by last name.
iii.Print the address, phone number, and date of birth(if it exists) of a
given person.
iv.Print the names of the people whose birthdays are in a given month
or between two given dates.
v.Print the names of all the people having the same status, such as
family, friend, or business.
vi.Print the names of all the people between two last names.
*/
#include "addressBookType.h"
#include <fstream>

addressBookType::addressBookType()
	:arrayListType<extPersonType>(500) {
}

//constructors
addressBookType::addressBookType(const string& new_fileName) {

}

int addressBookType::find(const string& lastName) const {
	bool isInAddressBook = false;
	int p = 0;
	for (p = 0; p < length; p++)
		if (list[p].getLastName() == lastName) {
			isInAddressBook = true;
		}

	return isInAddressBook == true ? p : -1;
}
void addressBookType::print(const extPersonType& person) const {
	system("cls");
	bool isFound = false;
	for (int i = 0; i < length; i++) {
		if (person.getLastName() == list[i].getLastName()) {
			list[i].print();
			isFound = true;
		}
	}
	if (!isFound) {
		cout << endl << "Last Name " << person.getLastName() << " not in address book" << endl;
	}
}


void addressBookType::print(relationShipType relationship) const {
	system("cls");
	for (int r = 0; r < length; r++)
		if (list[r].getRelationShip() == int(relationship)) {
			list[r].print();
		}
}


void addressBookType::print(const dateType& oldDate, const dateType& newDate) const {
	system("cls");
	dateType tempDate;
	int tempMonth;
	for (int d = 0; d < length; d++) {
		tempDate = list[d].getDOB();
		tempMonth = tempDate.getMonth();
		if (oldDate.getMonth() == tempMonth) {
			list[d].print();
		}
	}
}
void addressBookType::print(const string&  highLastName, const string& lowLastName) const {
	string high, low;
	if (highLastName > lowLastName) { //if the user enters them backwards.
		high = highLastName;
		low = lowLastName;
	} else {
		high = lowLastName;
		low = highLastName;
	}
	system("cls"); 
	for (int i = 0; i < length; i++) {
		if (list[i].getLastName() >= low && list[i].getLastName() <= high) {
			list[i].print();
		}
	}
}
void addressBookType::print() const {
	system("cls");
	if (length < 1) {
		cout << "address book empty!" << endl;
	} else {
		for (int n = 0; n < length; n++) {
			list[n].print();
		}
		cout << length << " Total Entries!" << endl;
	}
}


void addressBookType::deleteEntry(addressBookType &addressBook) {
	system("cls");
	string toDelete;
	bool isFound = false;
	cout << "Delete an entry" << endl;
	cout << "Enter a last name to delete from the address book: " << endl;
	getline(cin, toDelete);
	for (int d = 0; d < length; d++) {
		if (!isFound){
			if (list[d].getLastName() == toDelete) {
				addressBook.removeAt(d);
				cout << toDelete << " removed!" << endl;
				isFound = true;
			}
		}
	}
	if (!isFound) {
		cout << "Name not found" << endl;
	}
}

extPersonType addressBookType::addEntry() {
	system("cls");
	cout << "New Entry: " << endl;
	string fname, lname, street, city, state, zip, phone;
	int month, day, year;
	relationShipType r;
	dateType dob;
	cout << "First Name: " << endl;
	getline(cin, fname);
	cout << "Last Name: " << endl;
	getline(cin, lname);
	cout << "Street Address: " << endl;
	getline(cin, street);
	cout << "City: " << endl;
	getline(cin, city);
	cout << "State (2 digit abbreviation): " << endl;
	getline(cin, state);
	cout << "Zip Code: " << endl;
	getline(cin, zip);
	cout << "Phone Number: " << endl;
	getline(cin, phone);
	cout << "Day of Birth: " << endl;
	cin >> day;
	cin.ignore();
	cin.clear();
	cout << "Month Of Birth: " << endl;
	cin >> month;
	cin.ignore();
	cin.clear();
	cout << "Year Of Birth: " << endl;
	cin >> year;
	cin.ignore();
	cin.clear();

	dob.setDate(month, day, year);
	int rtype = 0;
	while (rtype != 1 && rtype != 2 && rtype != 3 && rtype != 4) {
	cout << "Relationship Type: " << endl;
	cout << "1. Friend" << endl << "2. Family" << endl << "3. Business" << endl << "4. Other" << endl;
		cin >> rtype;
		cin.ignore();
		cin.clear();
		if (rtype == 1) {
			r = FRIEND;
		} else if (rtype == 2) {
			r = FAMILY;
		} else if (rtype == 3) {
			r = BUSINESS;
		} else if (rtype == 4) {
			r = OTHER;
		}
	}

	extPersonType newPerson(fname, lname, phone, dob, r);
	newPerson.setAddress(street, city, state, zip);
	
	return newPerson;
}


void addressBookType::load(addressBookType &addressBook) {
	ifstream infile;

	string fname, lname;
	string street, city, state, zip, phone;
	int relationship;
	relationShipType r;
	int month, day, year;
	dateType dob;

	extPersonType temp; //to hold all temp data for each entry

	infile.open("addressBook.txt");
	if (!infile) {
		cout << "Cannot locate file. " << endl;
		return;
	} 

	int i = 0;

	while (infile >> fname) {
			//infile >> fname;
			infile >> lname;
			infile >> month >> day >> year;
			infile.ignore(1000, '\n');
			getline(infile, street);
			getline(infile, city);
			getline(infile, state);
			getline(infile, zip);
			getline(infile, phone);
			infile >> relationship;

			dob.setDate(month, day, year);

			r = static_cast<relationShipType>(relationship);

			temp.setExtPerson(fname, lname, phone, dob, r);
			temp.setAddress(street, city, state, zip);

			addressBook.insertAt(i, temp);
			i++;
		
	}
}

void addressBookType::save(addressBookType addressBook) {
	ofstream outfile;
	outfile.open("addressBook.txt");
	if (!outfile) {
		cout << "Input file does not exists. "
			<< "Program terminates!!!" << endl;
		return;
	}
	string fname, lname;
	string street, city, state, zip, phone;
	relationShipType r;
	dateType dob;

	for (int i = 0; i < addressBook.length; i++) {
		fname = addressBook.list[i].getFirstName();
		lname = addressBook.list[i].getLastName();
		dob = addressBook.list[i].getDOB();
		phone = addressBook.list[i].getTelephoneNumber();
		street = addressBook.list[i].getStreetAddress();
		city = addressBook.list[i].getCity();
		state = addressBook.list[i].getState();
		zip = addressBook.list[i].getZipCode();
		r = addressBook.list[i].getRelationShip();

		outfile << fname << endl;
		outfile << lname << endl;
		outfile << dob.getMonth() << " " << dob.getDay() << " " << dob.getYear() << endl;
		outfile << street << endl;
		outfile << city << endl;
		outfile << state << endl;
		outfile << zip << endl;
		outfile << phone << endl;
		outfile << r << endl << endl;
	}
}