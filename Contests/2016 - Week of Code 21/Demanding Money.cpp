#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// So close!!! Passes 30% of the test cases with timeouts for the remaining ones.
// If you modify this approach to completely use bit masks you can get it to pass 80% of the 
// test cases. To pass all of them, you need to figure out a way to break down the vertices
// into 2 sets, find the maxMoneyRobbed/numWays in one of them and then iterate over the 
// independent sets in the other one to come up with a combined solution that uses each piece. 


// Global variables to avoid excessive passing to the recursive function 
// ^^ passing by value is expensive yo
int maxMoneyRobbed = 0, numWays = 0, V;
int *C;
bool **matrix;

// Returns true if adding the vertex to the set keeps the set independent, false otherwise
bool canAddVertex(stack<int> set, int vertex) {
	while(set.size() > 0) {
		int vertexInSet = set.top();
		if(matrix[vertex][vertexInSet]) {
			return false;
		}		
		set.pop();
	}
	return true;
}

// Recursively finds all the independent sets in the graph
void findIndependentSets(stack<int> set) {
	// Construct independent sets recursively
	for(int i = set.top() + 1; i < V; i++) {
		if(canAddVertex(set, i)) {
			set.push(i);
			findIndependentSets(set);
			set.pop();
		}
	}
	// After finishing an independent set, check if it's a candidate for Killgrave
	int moneyRobbed = 0;
	while(set.size() > 0) {
		moneyRobbed += C[set.top()];
		set.pop();
	}
	if(moneyRobbed > maxMoneyRobbed) {
		maxMoneyRobbed = moneyRobbed;
		numWays = 1;
	} else if(moneyRobbed == maxMoneyRobbed) {
		numWays++;
	}
}

int main() {
	// Read input
	int E;
	cin>>V>>E;
	C = new int[V];
	for(int i = 0; i < V; i++) {
		cin>>C[i];
	}
	// Use an adjacency matrix to represent the graph
	matrix = new bool*[V];
	for(int i = 0; i < V; i++) {
		matrix[i] = new bool[V];
		for(int j = 0; j < V; j++) {
			matrix[i][j] = false;
		}
	}
	for(int i = 0; i < E; i++) {
		int s, d;
		cin>>s>>d;
		matrix[s-1][d-1] = true;
		matrix[d-1][s-1] = true;
	}
	// Find all of the independent sets in the graph
	for(int i = 0; i < V; i++) {
		stack<int> independentSet;
		independentSet.push(i);
		findIndependentSets(independentSet);
	}
	cout<<maxMoneyRobbed<<" "<<numWays;
    return 0;
}
