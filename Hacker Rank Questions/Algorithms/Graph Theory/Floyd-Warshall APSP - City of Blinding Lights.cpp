#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

// Floyd-Warshall is an APSP (all pairs shortest path) algorithm
// - When the algorithm finishes, the shortest path between any two vertices in the graph will be known
// - Note: We could just call Dijkstra's or Bellman-Ford on every vertex in the graph, but Floyd-Warshall
// is more efficient

int main() {
    int V, E;
    cin>>V>>E;

    // Create array of minimum distances initialized to ∞ (infinity)
    // When Floyd-Warshall finishes, dist[i][j] represents the shortest distance from vertex i to vertex j
    int **dist = new int*[V];
    for(int i = 0; i < V; i++) {
        dist[i] = new int[V];
        for(int j = 0; j < V; j++) {
            if(i != j) {
                dist[i][j] = INT_MAX;
            } else {
                dist[i][j] = 0;
            }
        }
    }

    // Insert E edges
    for (int i = 0; i < E; ++i) {
        int s, d, w;
        cin>>s>>d>>w;
        dist[s-1][d-1] = w;
    }

    // Perform Floyd-Warshall Algorithm
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            for (int k = 0; k < V; ++k) {
                if(dist[j][i] == INT_MAX || dist[i][k] == INT_MAX) {
                    continue; // We only want to compare non-infinite paths
                }
                if(dist[j][k] > dist[j][i] + dist[i][k]) {
                    dist[j][k] = dist[j][i] + dist[i][k]; // Update dist since we've found a shorter path
               }
            }
        }
    }

    // Print out solution
    int Q = 0;
    cin>>Q;
    for(int i = 0; i < Q; i++) {
        int a, b;
        cin>>a>>b;
        if(dist[a-1][b-1] == INT_MAX) {
            cout<<"-1"<<"\n"; // Unreachable node
        } else {
            cout<<dist[a-1][b-1]<<"\n";
        }
    }

    return 0;
}