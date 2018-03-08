#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

//Program read graph from .txt file.

/* Example file input:

5
1 2
1 3
1 4
2 3
2 5
2 4
2 1
3 2
3 1
4 1
4 2
5 2
*/


vector<int> *graph; // Main graph

bool used[100]; //Used vertexes

void dfs(int);

int main() {

	int N, left, right;
	ifstream file("d:\\graphnull.txt");

	if (file) { //if file is open

		file >> N; //read count of Vertexes	
		graph = new vector<int>[N+1];

		while (!file.eof()) { // while not end of file (EOF)
			file >> left >> right; //read from file and write
			graph[left].push_back(right);
		}

		int vertex;
		cout << "Set vertex from which to start the search: ";
		cin >> vertex;

		cout << "DFS at vertex: \n";
		dfs(vertex); //Start from vertex 

	} file.close();

	system("pause");
}

void dfs(int v) {
	used[v] = true;
	cout << v << " ";
	for (auto u : graph[v]) {
		if (!used[u]) {
			dfs(u);
		}
	}
}