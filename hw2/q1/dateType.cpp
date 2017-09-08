//Implementation file date

#include <iostream>
#include "dateType.h"

using namespace std;

void dateType::setDate(int month, int day, int year) {
	dYear = year;

	if ((month >= 1) && (month <= 12)) {
		dMonth = month;
	}

	if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
		if ((day >= 1) && (day <= 30)) {
			dDay = day;
		}
	}
	else if (month == 2) {
		if (isLeapYear(year) == false) {
			if ((day >= 1) && (day <= 28)) {
				dDay = day;
			}
		}
		else if (isLeapYear(year) == true) {
			if ((day >= 1) && (day <= 29)) {
				dDay = day;
			}
		}
	}
	else {
		if ((day >= 1) && (day <= 31)) {
			dDay = day;
		}
	}
}

int dateType::getDay() const {
	return dDay;
}

int dateType::getMonth() const {
	return dMonth;
}

int dateType::getYear() const {
	return dYear;
}

void dateType::printDate() const {
	cout << dMonth << "-" << dDay << "-" << dYear;
}

//Constructor with parameters
dateType::dateType(int month, int day, int year) {
	setDate(month, day, year);
}

//custom function
bool dateType::isLeapYear(int year) {
	return (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0) ? true : false;
}

int dateType::getDaysInMonth(int month, int year) {
	if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
		return 30;
	}
	else if (month == 2) {
		if (isLeapYear(year) == false) {
			return 28;
		}
		else if (isLeapYear(year) == true) {
			return 29;
		}
	}
	else {
		return 31;
	}
	return 0;
}

int dateType::getDaysGoneByThisYear() {
	int totalDaysGoneBy = 0;
	if (getMonth() == 1) {
		return totalDaysGoneBy += getDay();
	}
	else {
		for (int i = 1; i < getMonth(); i++) {
			totalDaysGoneBy += getDaysInMonth(i, getYear());
		}
		return totalDaysGoneBy += getDay();
	}
	//symbolic..
	return 0;
}

int dateType::getDaysUntilNextYear() {
	return (isLeapYear(getYear()) == true) ? (366 - getDaysGoneByThisYear()) : (365 - getDaysGoneByThisYear());
}

void dateType::getDaysFromNow(int daysFromNow) {
	int newMonth = getMonth();
	int newDay = getDay();
	int newYear = getYear();
	int totalDays = newDay + daysFromNow;

	if (totalDays > getDaysInMonth(newMonth, newYear)) {
			totalDays = totalDays - getDaysInMonth(newMonth, newYear);
		newMonth++;
		if (newMonth = 13) {
			newYear++;
			newMonth = 1;
		} else {
			newMonth++;
		}
	} else newDay = totalDays;
	setDate(newMonth, newDay, newYear);
	cout << daysFromNow << " days from today: " << endl;
	cout << getMonth() << " " << getDay() << " " << getYear() << endl;
}