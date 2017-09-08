#pragma once
#include "arrayListType.h"
#include "extPersonType.h"

class addressBookType :
	public arrayListType<extPersonType>
{
public:
	//constructors
	addressBookType();
	addressBookType(const string& new_fileName);

	int find(const string& lastName) const;
	void print(const extPersonType& person) const;
	void print(relationShipType relationship) const;
	void print(const dateType& oldDate, const dateType& newDate) const;
	void print(const string&  highLastName, const string& lowLastName) const;
	void print() const;
};