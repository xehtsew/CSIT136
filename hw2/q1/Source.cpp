#include <iostream>
#include "dateType.h"

using namespace std;


int main() {

	dateType d;

	d.setDate(1, 29, 2004);

	cout << "day: " << d.getDay() << endl;
	cout << "month: " << d.getMonth() << endl;
    cout <<	"year: " << d.getYear() << endl;

	cout << "-----------change date-------------" << endl;
	dateType d2;
	d2.setDate(12, 12, 2016);
	cout << "day: " << d2.getDay() << endl;
	cout << "month: " << d2.getMonth() << endl;
	cout << "year: " << d2.getYear() << endl;
	
	cout << "Number of Days in the " << d2.getMonth() << " month: " << endl;
	cout << d2.getDaysInMonth(d2.getMonth(), d2.getYear()) << endl;
	cout << "Days gone by this year: " << d2.getDaysGoneByThisYear() << endl;
	cout << "Days Until Next Year: " << d2.getDaysUntilNextYear() << endl;
	cout << "What day will it be" << endl;
	d2.getDaysFromNow(20);
	cout << endl;


	system("pause");
	return 0;
}