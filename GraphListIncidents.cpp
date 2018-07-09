#include "stdafx.h"
#include <iostream>
#include <list>
#include <vector>
#include <fstream>
using namespace std;

/*Algorithm complexity is O(N^2) calculations',
where O - is complexity and N - is count of vertexes*/

int main()
{	
	int N, left, right;
	ifstream file("d:\\graphnull.txt");

	if (file) { //if file is open

		file >> N; //read count of Vertexes	
		vector <list<int> > adjList(N);

		for (int i = 0; i < N * 2; i++) {
			file >> left >> right; //read and write
			adjList[--left].push_back(--right);
		}

		vector<list<int> >::iterator i;
		int c = 1;
		cout << "Vertexes that are connected: " << endl;

		for (vector<list<int> >::iterator i = adjList.begin(); i != adjList.end(); i++) {
			cout << c << ": ";
			list<int> li = *i;
			for (list<int>::iterator j = li.begin(); j != li.end(); j++) {
				cout << *j+1 << " ";
			}
			cout << endl;
			c++;
		}
	} file.close();
	system("pause");
}
