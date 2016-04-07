#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

// Prim's Algorithm is a greedy node-based algorithm that finds a MST (minimum spanning tree) in a graph
// Description of Algorithm:
// 1. Begin with a set of visited nodes that originally only contains the starting node
// 2. Iterate over the set of visited nodes and find the minimum weighted edge connecting a visited node with an unvisited node
// 3. Add the unvisited node to the set of visited nodes and add the weight of the edge to the size of the MST
// 4. Repeat step 2-3 until there are no longer any unvisited nodes
// Total runtime: Current implementation is O(V^3) but we can reduce this significantly
// We can get it down to O(V^2) using a more clever way to store the solved vertices
// We can get it down to O(ElogV) using a fibonacci heap + adjacency list 
// See: http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/ for more details

int main() {
	int N, M, S;
	cin>>N>>M;
	// Initialize graph
	int **adjacency_matrix = new int*[N];
	for(int i = 0; i < N; i++) {
		adjacency_matrix[i] = new int[N];
		for(int j = 0; j < N; j++) {
			adjacency_matrix[i][j] = -1;
		}
	}
	for(int i = 0; i < M; i++) {
		int x, y, r;
		cin>>x>>y>>r;
		if(adjacency_matrix[x-1][y-1] != -1) {
			// In case of an existing edge, choose the edge with a smaller weight
			if(r < adjacency_matrix[x-1][y-1]) {
				adjacency_matrix[x-1][y-1] = r;
				adjacency_matrix[y-1][x-1] = r;
			}
		} else {	
			adjacency_matrix[x-1][y-1] = r;
			adjacency_matrix[y-1][x-1] = r;
		}
	}
	// Perform Prim's Algorithm
	bool finished = false;
	int size = 0;
	bool *visited = new bool[N];
	// Start at node S and keep traversing until all reachable nodes from S have been visited
	// visited = node is in our spanning tree, !visited = node is not in our spanning tree
	cin>>S;
	visited[S-1] = true;
	bool found_unvisited = true;
	while(found_unvisited) {
		found_unvisited = false;
		int unvisited_node = 0;
		// Look for the smallest edge that connects one of our visited nodes with an unvisited node
		int min_edge = INT_MAX; // Start with the large possible edge value
		for(int i = 0; i < N; i++) {
			// If the node is in our visited set, check it's adjacent nodes for a minimum edge
			if(visited[i]) {
				for(int j = 0; j < N; j++) {
					// If there's an edge between our visited node (i) and an unvisited node (j)
					if(!visited[j] && adjacency_matrix[i][j] != -1) {
						found_unvisited = true;
						if(adjacency_matrix[i][j] < min_edge) {
							unvisited_node = j;
							min_edge = adjacency_matrix[i][j];
						}
					}
				}
			}
		}
		if(found_unvisited) {
			// Add the node to our set and increase the size the spanning tree
			visited[unvisited_node] = true;
			size += min_edge;
		}
	}
	cout<<size<<"\n";
    return 0;
}