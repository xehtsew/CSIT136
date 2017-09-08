//Write a program that outputs the shortest distance from a given node to
//every other node in the graph.
#include <iostream>
#include <fstream>
#include "weightedGraph.h"

using namespace std;

int main()
{ 	
	weightedGraphType wg;
	wg.createWeightedGraph();
	wg.printGraph();

	for (int i = 0; i < wg.getGSize(); i++) {
		wg.shortestPath(i);
		wg.printShortestDistance(i);
	}
	system("pause");
	return 0;
}