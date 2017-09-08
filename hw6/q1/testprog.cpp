//******************************************************
// Author: D. S. Malik
//
// Program: Decimal to binary
// This program uses recursion to find the binary
// representation of a nonnegative integer.
//******************************************************
#include <iostream>
using namespace std;
void decToBin(int num, int base);

int main()
{
	int decimalNum;
	int base;
	cout << "Enter number in decimal: " << endl;
	cin >> decimalNum;
	cout << "Enter base to multiply by: " << endl;
	cin >> base;
	cout << endl;
	cout << "Decimal " << decimalNum << " = ";
	decToBin(decimalNum, base);
	cout << " base " << base << endl;

	system("pause");
	return 0;
}

//////////////////////////////////////////////////////////////
//			This is the closest I could get here... but		//
//			it puts a 0 at the beginning of all of the		//
//			responses.....									//
//////////////////////////////////////////////////////////////

void decToBin(int num, int base) {
	int temp = 0;
		if (num > 0) {
				temp = num % base;
				num = num / base;
				decToBin(num, base);
		} if (temp > 9) {
			switch (temp) {
			case 10: cout << "A"; break;
			case 11: cout << "B"; break;
			case 12: cout << "C"; break;
			case 13: cout << "D"; break;
			case 14: cout << "E"; break;
			case 15: cout << "F"; break;
			case 16: cout << "G"; break;
			case 17: cout << "H"; break;
			case 18: cout << "I"; break;
			case 19: cout << "J"; break;
			}
		} else {
			cout << temp;
		}
}
