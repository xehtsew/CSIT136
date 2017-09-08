#pragma once
#include "dateType.h"
#include "personType.h"

enum relationShipType {FAMILY, FRIEND, BUSINESS, OTHER};

class extPersonType :
	public personType
{
public:
	//constructors
	extPersonType();
	extPersonType(const string& new_firstName, const string& new_lastName, const string& new_telephoneNumber, const dateType& new_dob, relationShipType new_relationship);

	//accessors
	void getExtPerson(string& new_firstName, string& new_lastName, string& new_telephoneNumber, dateType& new_dob, relationShipType& new_relationship) const;
	string getFirstName() const;
	string getLastName() const;
	string getTelephoneNumber() const;
	dateType getDOB() const;
	relationShipType getRelationShip() const;

	//mutators
	void setExtPerson(const string& new_firstName, const string& new_lastName, const string& new_telephoneNumber, const dateType& new_dob, relationShipType new_relationship);
	void setFirstName(const string& new_firstName);
	void setLastName(const string& new_lastName) const;
	void setTelephoneNumber(const string& new_telephoneNumber);
	void setDOB(const dateType& new_dob);
	void setRelationShip(relationShipType new_relationShip) const;

	//custom method
	void print() const;

private:
	string _telephoneNumber;
	relationShipType _relationship;
	dateType dob;
};