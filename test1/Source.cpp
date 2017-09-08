#include "ModuloZ.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	ModuloZ a = ModuloZ(); //default constructor
	ModuloZ b = ModuloZ(1); //default constructor, 1 parameter

	ModuloZ c = ModuloZ(-13, 8); 
	c.show();//returns c.n(normalized) = 3

	ModuloZ d = ModuloZ(13, 8); 
	d.show();//returns d.n(normalized) = 5

	ModuloZ e = ModuloZ(7, 8); 
	e.show();//returns e.n(normalized) = 7

	ModuloZ f = ModuloZ(-5, 8); 
	f.show();//returns f.n(normalized) = 3

	//test ADD
	ModuloZ g = e.add(f);
	g.show();//returns g.n(e.n(normalized) + f.n(normalized)) = 2

	/*
	this generates bad assertion due to incongruent z values
	ModuloZ h = ModuloZ(7, 8);
	ModuloZ i = ModuloZ(-5, 4);
	ModuloZ j = h.add(i); <- crashes here, bad z values
	j.show(); <- wont step to this level... added for posterity
	*/

	//multiply
	ModuloZ k = ModuloZ(3, 8);
	ModuloZ l = ModuloZ(4, 8);
	ModuloZ m = k.mul(l);
	m.show(); //returns m.n((k.n(normalized)) * (l.n(normalized)) = 4

	system("pause");
	return 0;
}