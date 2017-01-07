#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

// Incomplete solution, passes 1/4th of the test cases but was my best attempt! :)
// Use a DFS to construct a minimum spanning tree from each node, traverse edges with the 
// smallest value first since 2^0 + 2^1 + 2^2 + ... 2^(n-1) < 2^n. In other words for a given edge,
// it would be a shorter distance to traverse ALL of the edges with a smaller weight than that edge.
// Thus in the DFS, every time we visit a vertex we pop all of its edges into a sorted set, and 
// traverse the smallest edge each time.

//adds the two bit strings and return the result
string addBitStrings( string first, string second );
 
// Helper method: given two unequal sized bit strings, converts them to
// same length by aadding leading 0s in the smaller string. Returns the
// the new length
int makeEqualLength(string &str1, string &str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 < len2)
    {
        for (int i = 0 ; i < len2 - len1 ; i++)
            str1 = '0' + str1;
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0 ; i < len1 - len2 ; i++)
            str2 = '0' + str2;
    }
    return len1; // If len1 >= len2
}
 
// The main function that adds two bit sequences and returns the addition
string addBitStrings( string first, string second )
{
    string result;  // To store the sum bits
 
    // make the lengths same before adding
    int length = makeEqualLength(first, second);
 
    int carry = 0;  // Initialize carry
 
    // Add all bits one by one
    for (int i = length-1 ; i >= 0 ; i--)
    {
        int firstBit = first.at(i) - '0';
        int secondBit = second.at(i) - '0';
 
        // boolean expression for sum of 3 bits
        int sum = (firstBit ^ secondBit ^ carry)+'0';
 
        result = (char)sum + result;
 
        // boolean expression for 3-bit addition
        carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    }
 
    // if overflow, then add a leading 1
    if (carry)
        result = '1' + result;
 
    return result;
}

int main() {
	int V, E; // # of vertices, # of edges
	cin>>V>>E;
	// Use an adjacency matrix to represent the graph
	int **matrix = new int*[V];
	for(int i = 0; i < V; i++) {
		matrix[i] = new int[V];
		for(int j = 0; j < V; j++) {
			matrix[i][j] = -1; // -1 = not connected
		}
	}
	// We should also maintain a list of edges to make our DFS easier
	pair<int,int> *edges = new pair<int,int>[E];
	for(int i = 0; i < E; i++) {
		int v1, v2, w;
		cin>>v1>>v2>>w;
		matrix[v1-1][v2-1] = w;
		matrix[v2-1][v1-1] = w;
		edges[w] = pair<int,int>(v1-1,v2-1);
	}
	string answer = "0";
	for(int i = 0; i < V; i++) {
		set<int> sortedEdges;
		int *visited = new int[V];
		for(int i = 0; i < V; i++) {
			visited[i] = false;
		}
		visited[i] = true;
		// Pop all of the edges connected to vertex i into sortedEdges
		for(int j = 0; j < V; j++) {
			if(matrix[i][j] != -1) {
				sortedEdges.insert(matrix[i][j]);
			}
		}
		bool visitedAllVertices = true;
		for(int i = 0; i < V; i++) {
			if(!visited[i]) {
				visitedAllVertices = false;
				break;
			}
		}
		string *dist = new string[E];
		for(int i = 0; i < E; i++) {
			dist[i] = string(E, '0');
		}
		while(!visitedAllVertices) {
			// Visit a new vertex
			auto it = sortedEdges.begin();
			int v1 = edges[*it].first;
			int v2 = edges[*it].second;
			bool edgeRemoved = false;
			if(!visited[v2]) {
				for(int j = 0; j < dist[v1].size(); j++) {
					if(dist[v1][j] == '1') {
						dist[v2][j] = '1';
					}
				}
				dist[v2][E-*it-1] = '1';
				if(v2 > i) {
					answer = addBitStrings(answer, dist[v2]);
				}
				visited[v2] = true;
				sortedEdges.erase(it); // remove the sortedEdge
				edgeRemoved = true;
				// Pop all of the edges connected to vertex v2 into sortedEdges
				for(int j = 0; j < V; j++) {
					if(matrix[v2][j] != -1) {
						sortedEdges.insert(matrix[v2][j]);
					}
				}
			} else if(!visited[v1]) {
				for(int j = 0; j < dist[v2].size(); j++) {
					if(dist[v2][j] == '1') {
						dist[v1][j] = '1';
					}
				} 
				dist[v1][E-*it-1] = '1';
				if(v1 > i) {
					answer = addBitStrings(answer, dist[v1]);
				}
				visited[v1] = true;
				sortedEdges.erase(it); // remove the sortedEdge
				edgeRemoved = true;
				// Pop all of the edges connected to vertex v1 into sortedEdges
				for(int j = 0; j < V; j++) {
					if(matrix[v1][j] != -1) {
						sortedEdges.insert(matrix[v1][j]);
					}
				}
			}
			if(!edgeRemoved) {
				sortedEdges.erase(it); // remove the sortedEdge
			}
			visitedAllVertices = true;
			for(int i = 0; i < V; i++) {
				if(!visited[i]) {
					visitedAllVertices = false;
					break;
				}
			}
		}
	}
	cout<<answer;
    return 0;
}
