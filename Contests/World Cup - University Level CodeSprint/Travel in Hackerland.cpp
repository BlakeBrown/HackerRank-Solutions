#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

// Kruskal's Algorithm is a greedy edge-based algorithm that finds a MST (minimum spanning tree) in a graph
// Description of Algorithm:
// 1. Create a set E containing all edges in the graph
// 2. Sort E
// 3. Remove the minimum edge from E and include it in the MST as long as it doesn't create a cycle!
// 4. Repeat step 3 until the MST is complete or E is empty

// A structure to represent each edge in the graph
struct Edge {
	int s, d; // Source node, destination node
    long long sType, dType, w; // T(i) for s and d, w = weight
};

// A structure to represent a subset for union-find
struct subset
{
    int parent;
    int rank;
};
 
// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i)
{
    // Find root and make root as parent of i (path compression)
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}
 
// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank){
        subsets[yroot].parent = xroot;
    } else {
    	// If ranks are same, then make one as root and increment its rank by one
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare two edges according to their weights
// Used in qsort() for sorting an array of edges
int edgeComparison(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->w > b1->w;
}

int main() {
	int V, E, Q;
	cin>>V>>E>>Q;
    long long *type = new long long[V+1];
    for(int i = 1; i <= V; i++) {
        cin>>type[i];
    }
    // Initialize array containing all of our edges
    struct Edge* edge = (struct Edge*) malloc(E*sizeof(struct Edge));
    // Insert E edges
    for (int i = 0; i < E; ++i)
    {
        int s, d;
        long long w; // weight is really just crowd value here
        cin>>s>>d>>w;
        edge[i].s = s;
        edge[i].d = d;
        edge[i].w = w;
    }

    // === STEP 1: PERFORM KRUSKALS ALGORITHM ===

    // Sort the edges
    qsort(edge, E, sizeof(edge[0]), edgeComparison);

    // Initialize a set to store the resultant MST
    struct Edge mst[E];
    int mstSize = 0;

    // Create V subsets with single elements (this represents our spanning tree)
    struct subset *subsets = (struct subset*) malloc( V * sizeof(struct subset) );
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Perform Kruskal's Algorithm
    for(int i = 0; i < E; i++) {
        // Get the minimum edge in E
        struct Edge minEdge = edge[i];
        // Use the Union-Find algorithm to check if E causes a cycle
        int x = find(subsets, minEdge.s-1);
        int y = find(subsets, minEdge.d-1);
        // If including this edge does't cause cycle, include it in the MST
        if (x != y) {
            mst[mstSize++] = minEdge;
            Union(subsets, x, y);
        }
    }
    // === STEP 2: FOR EACH QUERY, ALWAYS MOVE TO CITY WITH LOWEST WEIGHT ===
    int x, y, k;
    for(int i = 0; i < Q; i++) {
    	cin>>x>>y>>k;
    	while(k > 0) {
    		for(int i = 0; i < mstSize; i++) {
    			if()
    		}
    	}
    }

    return 0;
}