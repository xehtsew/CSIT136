#pragma once
#include <vector>
#include <iostream>
#include "Jar.h"
using namespace std;

class TheJarsProblem: public Jar {
public:
	TheJarsProblem();
	~TheJarsProblem();
	TheJarsProblem(vector<Jar>);
	void divide();
	void read(int& source, int& destination);
	void pour(int source, int destination);
	void show(int count);
private:
	vector<Jar> jars;
};

