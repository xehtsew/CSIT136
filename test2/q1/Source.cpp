#include <iostream>

using namespace std;
int recursiveGCD(int num1, int num2);
int nonrecursiveLCM(int num1, int num2);

int main() {

	cout << recursiveGCD(560, 160) << endl;
	cout << nonrecursiveLCM(456,777) << endl;
	system("pause");

	return 0;
}

//divide function calls recursively
//recursive GCD sends two numbers, and "num2" as the divisor to be subtracted from.
int divide(int num1, int num2, int divisor) {
	if ((num1 % divisor == 0) && (num2 % divisor == 0)) {
		return divisor;
	} else {
		divide(num1, num2, divisor - 1);
	}
}

//main function, calls divide function. divide calls itself recurisvely.
int recursiveGCD(int num1, int num2) {
	if (num1 < 0) {
		num1 *= -1;
	} if (num2 < 0) {
		num2 *= -1;
	} if (num1 == 0 || num2 == 0) {
		return 1;
	}
	//send two numbers and a divsor to subtract 1 from and caclulate modulus.
	return divide(num1, num2, num2);

}


//lcm calls recursive GCD with its parameters, then returns the formula.
int nonrecursiveLCM(int num1, int num2) {
	if (num1 < 0) {
		num1 *= -1;
	} if (num2 < 0) {
		num2 *= -1;
	}
	return (num1 * num2) / recursiveGCD(num1, num2);
}