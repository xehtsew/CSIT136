#include "binaryTree.h"
#include "binarySearchTree.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Candidate {
	string name;
	int votes;
	friend ostream& operator << (ostream& outs, const Candidate& other) {
		outs << other.name << ", " << other.votes;
		return outs;
	}
	bool operator<(const Candidate& other) {return name < other.name;}
	bool operator>(const Candidate& other) {return name > other.name;}
	bool operator==(const Candidate& other) {return name == other.name;}
};
int main() {
	ifstream inputFile;
	inputFile.open("names.txt");
	Candidate c;
	Candidate updatedCandidate;
	Candidate winner;
	bSearchTreeType<Candidate> btree;

	if (!inputFile) {
		cout << "cannot find file" << endl;
	} else {
		while (inputFile >> c.name >> c.votes) {
			if (btree.search(c)) {
				cout << c.name << " found... updating votes" << endl;
				updatedCandidate = btree.getCandidate(c);
				updatedCandidate.votes += c.votes;
				btree.deleteNode(c);
				btree.insert(updatedCandidate);
				if (updatedCandidate.votes > winner.votes) {
					winner = updatedCandidate;
				}

			} else {
				cout << c.name << " not found...inserting..." << endl;
				btree.insert(c);
				if (c.votes > winner.votes) {
					winner = c;
				}
			}
		}
	}
	cout << endl << endl << "The Tree: " << endl;
	btree.inorderTraversal();
	cout << endl << endl;
	cout << winner.name << " wins with " << winner.votes << " votes!" << endl << endl;

	cout << "Tree node count: " << endl;
	cout  << btree.treeNodeCount() << endl << endl;

	inputFile.close();
	system("pause");

    return 0;
}