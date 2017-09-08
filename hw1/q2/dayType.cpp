#include "dayType.h"
#include <iostream>

dayType::dayType() {
	setDay(0);
}
//accessors
string dayType::getDay() {
	return (daysOfWeek[dayNo]);
}
string dayType::returnYesterday() {
	return (daysOfWeek[dayNo]) == "Monday" ? "Sunday" : (daysOfWeek[(dayNo - 1) % 7]);
}
string dayType::returnTomorrow() {
	return (daysOfWeek[dayNo]) == "Sunday" ? "Monday" : (daysOfWeek[(dayNo + 1) % 7]);
}
void dayType::printDay() {
	cout << (daysOfWeek[dayNo]);
}
//mutators
void dayType::setDay(int newDay) {
	dayNo = newDay;
}
//custom methods
string dayType::returnXDaysFromNow(int daysToCalculate) {
	return (daysOfWeek[(dayNo + daysToCalculate) % 7]);
}