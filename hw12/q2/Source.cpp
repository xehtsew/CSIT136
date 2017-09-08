//1. Write a program that outputs the nodes of a graph in a depth - first traversal.
#include <iostream>
#include <string>
#include "graphType.h"

using namespace::std;

int main() {
	graphType g;
	g.clearGraph();
	g.createGraph();
	g.depthFirstTraversal();
	cout << endl;
	system("pause");
	return 0;
}