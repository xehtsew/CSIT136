#include "extPersonType.h"
#include "addressType.h"
#include <iostream>

extPersonType::extPersonType() {
	dateType defaultDOB;
	setExtPerson("Matt", "Belluardo", "555-5555", defaultDOB, OTHER);
}

extPersonType::extPersonType(const string& new_firstName, const string& new_lastName,
	const string& new_telephoneNumber, const dateType& new_dob, relationShipType new_relationship) {
	setFirstName(new_firstName);
	setLastName(new_lastName);
	setTelephoneNumber(new_telephoneNumber);
	setDOB(new_dob);
	setRelationShip(new_relationship);
}

//accessors
void extPersonType::getExtPerson(string& new_firstName, string& new_lastName,
	string& new_telephoneNumber, dateType& new_dob, relationShipType& new_relationship) const {
	
}
string extPersonType::getFirstName() const {
	return personType::getFirstName();
}
string extPersonType::getLastName() const {
	return personType::getLastName();
}
string extPersonType::getTelephoneNumber() const {
	return _telephoneNumber;
}
dateType extPersonType::getDOB() const{
	return dob;
}
relationShipType extPersonType::getRelationShip() const {
	return _relationship;
}


//mutators
void extPersonType::setExtPerson(const string& new_firstName, const string& new_lastName,
	const string& new_telephoneNumber, const dateType& new_dob, relationShipType new_relationship) {
	personType::setName(new_firstName, new_lastName);
	setTelephoneNumber(new_telephoneNumber);
	setDOB(new_dob);
	setRelationShip(new_relationship);
}
void extPersonType::setFirstName(const string& new_firstName) {
	personType::setFirstName(new_firstName);
}
void extPersonType::setLastName(const string& new_lastName)  {
	personType::setLastName(new_lastName);
}
void extPersonType::setTelephoneNumber(const string& new_telephoneNumber) {
	_telephoneNumber = new_telephoneNumber;
}
void extPersonType::setDOB(const dateType& new_dob) {
	dob = new_dob;
}
void extPersonType::setRelationShip(relationShipType new_relationShip)  {
	_relationship = new_relationShip;
}

//custom method
void extPersonType::print() const {
	cout << getFirstName() << endl;
	cout << getLastName() << endl;
	cout << getTelephoneNumber() << endl;
	dateType dob = getDOB();
	cout << dob.getDay() << " " << dob.getMonth() << " " << dob.getYear() << endl;

	relationShipType r = getRelationShip();
	if (r == 0) {
		cout << "FAMILY" << endl;
	} else if (r == 1) {
		cout << "FRIEND" << endl;
	} else if (r == 2) {
		cout << "BUSINESS" << endl;
	} else if (r == 3) {
		cout << "OTHER" << endl;
	}
	getAddress();
	cout << endl;

}