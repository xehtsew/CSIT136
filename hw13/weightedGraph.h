#pragma once

//***************************************************************
// Author: D.S. Malik
//
// class weightedGraphType
// This class specifies the operations to find the weight of the
// shortest path from a given vertex to every other vertex in a
// graph.
//****************************************************************
#include <cassert>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cfloat>
#include "graphType.h"

using namespace std;

class weightedGraphType: public graphType
{
public:
    void createWeightedGraph();
      //Function to create the graph and the weight matrix.
      //Postcondition: The graph using adjacency lists and 
      //    its weight matrix is created.

    void shortestPath(int vertex);
      //Function to determine the weight of a shortest path 
      //from vertex, that is, source, to every other vertex 
      //in the graph.
      //Postcondition: The weight of the shortest path from vertex
      //    to every other vertex in the graph is determined.

    void printShortestDistance(int vertex);
      //Function to print the shortest weight from the vertex 
      //specified by the parameter vertex to every other vertex in 
      //the graph.
      //Postcondition: The weight of the shortest path from vertex
      //    to every other vertex in the graph is printed.

    weightedGraphType(int size = 0); 
      //Constructor
      //Postcondition: gSize = 0; maxSize = size;
      //    graph is an array of pointers to linked lists.
      //    weights is a two-dimensional array to store the weights
      //       of the edges.
      //    smallestWeight is an array to store the smallest weight
      //       from source to vertices.

    ~weightedGraphType();
      //Destructor
      //The storage occupied by the vertices and the arrays
      //weights and smallestWeight is deallocated.


protected:
	const double infinity = numeric_limits<double>::max();
    double **weights;   //pointer to create weight matrix
    double *smallestWeight; //pointer to create the array to store
                     //the smallest weight from source to vertices
};


void weightedGraphType::createWeightedGraph()
{
	createGraph();

	ifstream infile;
	string fileName;
	cout << "Enter weighted graph input file name: ";

	cin >> fileName;
	cout << endl;

	infile.open(fileName.c_str());
	assert(infile);

	int nVertices;
	infile >> nVertices;
	assert(nVertices == gSize);

	smallestWeight = new double[gSize];
	weights = new double*[gSize];
	for (int i = 0; i < gSize; i++)
	{
		weights[i] = new double[gSize];
		for (int j = 0; j < gSize; j++)
		{
			double weight;
			infile >> weight;
			if (weight == -1) weight = infinity;
			weights[i][j] = weight;
		}
	}
	infile.close();
} //createWeightedGraph

void weightedGraphType::shortestPath(int vertex)
{
    for (int j = 0; j < gSize; j++)
        smallestWeight[j] = weights[vertex][j];

    bool *weightFound;
    weightFound = new bool[gSize];

    for (int j = 0; j < gSize; j++)
        weightFound[j] = false;

    weightFound[vertex] = true;
    smallestWeight[vertex] = 0;

    for (int i = 0; i < gSize - 1; i++)
    {
        double minWeight = infinity;
        int v = -1;

        for (int j = 0; j < gSize; j++)
            if (!weightFound[j])
                if (smallestWeight[j] < minWeight) {
                    v = j;
                    minWeight = smallestWeight[v];
                }
		if (v != -1) {
			weightFound[v] = true;

			for (int j = 0; j < gSize; j++)
				if (!weightFound[j])
					if (minWeight + weights[v][j] < smallestWeight[j])
						smallestWeight[j] = minWeight + weights[v][j];
		}
    } //end for
} //end shortestPath

void weightedGraphType::printShortestDistance(int vertex) {
    cout << "Source Vertex: " << vertex << endl;
    cout << "Shortest distance from source to each vertex." << endl;
    cout << "Vertex  Shortest_Distance" << endl;


/////////////////////////////////////////////////////////////////////////////////
    for (int j = 0; j < gSize; j++)
		if (smallestWeight[j] == infinity) {
			cout << setw(4) << j << setw(12) << "infinity" << endl;

		} else 
        cout << setw(4) << j << setw(12) << smallestWeight[j] << endl;
    cout << endl;
} //end printShortestDistance

    //Constructor
weightedGraphType::weightedGraphType(int size)
                  :graphType(size)
{
    weights = new double*[size];

    for (int i = 0; i < size; i++)
        weights[i] = new double[size];

    smallestWeight = new double[size];
}

    //Destructor
weightedGraphType::~weightedGraphType()
{
    for (int i = 0; i < gSize; i++)
       delete [] weights[i];

    delete [] weights;
    delete [] smallestWeight;
}