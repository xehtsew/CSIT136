#include "addressType.h"
#include <iostream>
using namespace std;
addressType::addressType() {
	setAddress("855 North Vermont Avenue", "Los Angeles", "California", "90029");
}
addressType::addressType(const string& new_streetAddress, const string& new_city, 
	const string& new_state, const string& new_zipCode) {
	setAddress(new_streetAddress, new_city, new_state, new_zipCode);
}

//accessors
void addressType::getAddress() const {
	cout << getStreetAddress() << endl;
	cout << getCity() << endl;
	cout << getState() << endl;
	cout << getZipCode() << endl;
}
string addressType::getStreetAddress() const {
	return _streetAddress;
}
string addressType::getCity() const {
	return _city;
}
string addressType::getState() const {
	return _state;
}
string addressType::getZipCode() const {
	return _zipCode;
}

//mutators
void addressType::setAddress(const string& new_streetAddress, const string& new_city, 
	const string& new_state, const string& new_zipCode) {
	_streetAddress = new_streetAddress;
	_city = new_city;
	_state = new_state;
	_zipCode = new_zipCode;

}
void addressType::setStreetAddress(const string& new_streetAddress) {
	_streetAddress = new_streetAddress;
}
void addressType::setCity(const string& new_city) {
	_city = new_city;
}
void addressType::setState(const string& new_state) {
	_state = new_state;
}
void addressType::setZipCode(const string& new_zipCode) {
	_zipCode = new_zipCode;
}