
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include "ugraph.h"

using namespace std;

int main(int argc, char* argv[]) {
	ifstream inputFile;
	ofstream outputFile;
	int NC, NQ, MNP;
	const int max = 30;
	string cannal_A, cannal_B, start_point;


	if (argc != 3) {
		cout << "use: " << argv[0] << " input_File output_File" << endl;
		return -1;
	}

	inputFile.open(argv[1]);

	if (!inputFile.is_open()) {
		cout << "File: \"" << argv[1] << "\" not found" << endl;
		return -1;
	}

	outputFile.open(argv[2]);
	
	UMatrixGraph <string> graph(max, false);

	inputFile >> NC;

	for (int i = 0; i < NC; i++) {
		inputFile >> cannal_A >> cannal_B;
		graph.addEdge(cannal_A, cannal_B);
	}

	inputFile >> NQ;

	for (int i = 0; i < NQ; i++) {
		inputFile >> start_point >> MNP;
		outputFile << "Case " << i + 1 << ": " << leftover(start_point, graph, MNP) 
			<< " ports not reachable from port " << start_point << " with MNP = " 
			<< MNP << "." << endl;
	}
	
	return 0;
}
