
//************************************************************
// Author: D.S. Malik
// 
// Implemenation file personType
//************************************************************

#include <iostream>
#include <string>
#include "personType.h"

using namespace std;

void personType::print() const {
	cout << firstName << " " << lastName;
}
void personType::setName(string first, string last) {
	firstName = first;
	lastName = last;
}
string personType::getFirstName() const {
	return firstName;
}
string personType::getLastName() const {
	return lastName;
}
//Default constructor
personType::personType() {
	firstName = "";
	lastName = "";
}
//Constructor with parameters
personType::personType(string first, string last) {
	firstName = first;
	lastName = last;
}
//HOMEWORK
//set first name
void personType::setFirstName(string first) {
	firstName = first;
}
//set last name
void personType::setLastName(string last) {
	lastName = last;
}

//set middle name
void personType::setMiddleName(string middle) {
	middleName = middle;
}

//get middle name
string personType::getMiddleName() {
	return middleName;
}

//check if a given first name is the same as this person
bool personType::checkFirstName(string first) {
	return first == firstName ? true : false;
}

//check if a given last name is the same as this person
bool personType::checkLastName(string last) {
	return last == lastName ? true : false;
}