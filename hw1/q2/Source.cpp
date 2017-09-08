#include <iostream>
#include "dayType.h"

using namespace std;

int main() {
	//local variables
	dayType day;
	char continu = 'y';
	int userDay = 0;

	//msg to user
	cout << "What day is it?" << endl;
	cout << "1. Monday \n2. Tuesday \n3. Wednesday \n4. Thursday \n5. Friday \n6. Saturday \n7. Sunday" << endl;

	//get user day
	cin >> userDay;

	//validate user day
	while (cin.fail() || userDay > 7 || userDay < 1) {
		cin.clear();
		cin.ignore();
		cout << "1 through 7 only please" << endl;
		cin >> userDay;
	}

	//set the day (minus 1 to align to array)
	day.setDay(userDay - 1);
	cout << "You chose "; 
	
	//print the day
	day.printDay();
	cout << endl << endl;
	
	//get the day
	cout << "Its currently " << day.getDay() << endl;
	
	//get the day + 1
	cout << "what day is it tomorrow?" << endl;
	cout << day.returnTomorrow() << endl;
	cout << "what day was it yesterday?" << endl;

	//get the day - 1
	cout << day.returnYesterday() << endl << endl;

	//custom method for # of days from today
	cout << "Enter a number of days from now to see what day it will be: " << endl;

	//get user input
	cin >> (day.numberOfDaysToCalculate);

	//validate user input
	while (cin.fail() || day.numberOfDaysToCalculate <= 0) {
		cin.clear();
		cin.ignore();
		cout << "Not a valid integer...try again" << endl;
		cin >> (day.numberOfDaysToCalculate);
	}

	//show user input back to user
	cout << "you entered: " << day.numberOfDaysToCalculate << endl;

	//return days from today.
	cout << day.returnXDaysFromNow(day.numberOfDaysToCalculate) << endl;
	system("pause");

	return 0;
}