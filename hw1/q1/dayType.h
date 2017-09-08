#pragma once
#include <string>
using namespace std;

const string daysOfWeek[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

class dayType {
public:
	//contructors
	dayType();

	//accessors
	string getDay();
	void printDay();
	string returnYesterday();
	string returnTomorrow();

	//mutators
	void setDay(int newDay);

	//custom methods
	string returnXDaysFromNow(int daysToCalculate);

	//public variable (so main can access directly)
	int numberOfDaysToCalculate;
	
private:
	int dayNo;
};

