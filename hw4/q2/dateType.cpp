#include "dateType.h"
int dateType::dom[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
dateType::dateType() {
	setDate(1, 1, 1900);
}
dateType::dateType(int new_month, int new_day, int new_year) {
	setDate(new_month, new_day, new_year);
}
//accessors
void dateType::getDate(int& new_month, int& new_day, int& new_year) const {

}
int dateType::getMonth() const {
	return _month;
}
int dateType::getDay() const {
	return _day;
}
int dateType::getYear() const {
	return _year;
}
//mutators
void dateType::setDate(int new_month, int new_day, int new_year) {
	setMonth(new_month);
	setDay(new_day);
	setYear(new_year);
}
void dateType::setMonth(int new_month) {
	_month = new_month;
}
void dateType::setDay(int new_day) {
	_day = new_day;
}
void dateType::setYear(int new_year) {
	_year = new_year;
}

//custom methods
bool dateType::isLeapYear() const {
	return (_year % 4 == 0) && (_year % 100 != 0) || (_year % 400 == 0) ? true : false;
}
