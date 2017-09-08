#include "safeArray.h"

safeArray::safeArray(void)
	:arrayListType<int>() {
}
safeArray::safeArray(int newSize)
	:arrayListType<int>(newSize), startIndex(0) {
}
safeArray::safeArray(int newStartIndex, int newSize)
	:arrayListType<int>(newSize), startIndex(newStartIndex) {
}
safeArray::safeArray(const safeArray& otherArray)
	:arrayListType<int>(otherArray) { 
}
safeArray::~safeArray(void) {
}
const safeArray& safeArray::operator= (const safeArray& otherArray) {
		arrayListType<int>::operator=(otherArray);
		startIndex = otherArray.startIndex;
		return *this;
}
bool safeArray::isItemAtEqual(int location,  int item) const {
	location = location - startIndex;
	return arrayListType<int>::isItemAtEqual(location, item);
}
void safeArray::insertAt(int location,  int insertItem) {
	location = location - startIndex;
	arrayListType<int>::insertAt(location, insertItem);
}
void safeArray::removeAt(int location) {
	location = location - startIndex;
	arrayListType<int>::removeAt(location);
}
void safeArray::retrieveAt(int location, int& retItem) const {
	location = location - startIndex;
	arrayListType<int>:: retrieveAt(location, retItem);
}
void safeArray::replaceAt(int location,  int repItem) {
	location = location - startIndex;
	arrayListType<int>:: replaceAt(location, repItem);
}


///////////////////////////////////////////////////////////////////////
int safeArray::seqSearch(int item) const {
	int location = arrayListType<int>::seqSearch(item);
	location = location + (startIndex * 0);
	return location;
}
////////////////////////////////////////////////////////////////////////
