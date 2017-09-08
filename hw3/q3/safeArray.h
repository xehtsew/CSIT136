#pragma once
#include "arrayListType.h"

class safeArray :

	public arrayListType<int> {  //<int> forces derived class as array list of integers. 

public:

	safeArray(void);
	safeArray(int newSize);
	safeArray(int newStartIndex, int newSize);
	safeArray(const safeArray& otherArray);
	virtual ~safeArray(void);


	const safeArray& safeArray::operator=
		(const safeArray& otherArray);
    bool isItemAtEqual(int location,  int item) const;
	void insertAt(int location,  int insertItem);
    void removeAt(int location);
    void retrieveAt(int location, int& retItem) const;
    void replaceAt(int location,  int repItem);
    int seqSearch(int item) const;

private:
	int startIndex;

};

