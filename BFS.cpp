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
int p[100];
int dist[100];

void bfs(int);
void print_way(int);

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
		bfs(vertex);
		cout << "Which vertex to come: ";
		cin >> vertex;
		print_way(vertex);
		 

	} file.close();

	system("pause");
}

void bfs(int u) {
	used[u] = true;
	p[u] = u;
	dist[u] = 0;
	queue<int> q;
	q.push(u);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < (int)graph[u].size(); i++) {
			int v = graph[u][i];
			if (!used[v]) {
				used[v] = true;
				p[v] = u;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}

void print_way(int u) {
	if (p[u] != u) {
		print_way(p[u]);
	}
	cout << u << ' ';
}

