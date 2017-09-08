#include "ModuloZ.h"
#include <iostream>
#include <string>
#include <cassert>
ModuloZ::ModuloZ() {
	z = 2;
	n = 1;
}
ModuloZ::ModuloZ(int newN) {
	n = newN;
	z = 2;
	normalize();
}
ModuloZ::ModuloZ(int newN, int newZ) {
	n = newN;
	assert(newZ >= 2);
	z = newZ;
	normalize();
}
//accessors
int ModuloZ::getN() const {
	return n;
}
int ModuloZ::getZ() const {
	return z;
}
//custom methods
//private
void ModuloZ::normalize() {
	n = n % z;
	if (n < 0) n = n + z;
}
//public
ModuloZ ModuloZ::add(ModuloZ toAdd) {
	ModuloZ sum;
	assert (z == toAdd.z);
	sum.z = z;
	sum.n = (n + toAdd.n) % z;
	return sum;
}
ModuloZ ModuloZ::mul(ModuloZ toMul) {
	ModuloZ prod;
	assert(z  == toMul.z);
	prod.n = (n * toMul.n) % z;
	return prod;
}
void ModuloZ::show() {
	cout << getN() << endl;
}
