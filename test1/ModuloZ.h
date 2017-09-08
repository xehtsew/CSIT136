#pragma once
using namespace std;
class ModuloZ {
public:
	//constructors
	ModuloZ();
	ModuloZ(int newN);
	ModuloZ(int newN, int newZ);
	//accessors
	int getN() const;
	int getZ() const;
	//custom method
	ModuloZ add(ModuloZ toAdd);
	ModuloZ mul(ModuloZ toMul);
	void show();
private:
	//variables
	int z;
	int n;
	//custom method
	void normalize();

};

