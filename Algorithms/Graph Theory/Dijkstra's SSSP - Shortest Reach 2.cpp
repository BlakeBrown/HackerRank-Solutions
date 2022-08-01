#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

// Dijkstra's is a greedy SSSP (single source shortest path) algorithm
// - When the algorithm finishes, the shortest distance from source to all other vertex's in the graph will be known
// - Dikstra's only works for graphs with positive edge weights (use Bellman-Ford for negative edge weights)
// Description of Algorithm:
// 1. Create a set of unvisited vertices, all with initial distance INF
// 2. Mark the source node as visited with distance 0, update its neighbours to have distance equal to their edge weight
// 3. Find the unvisited vertex with the minimum distance (call it U)
// 4. Calculate the distance from U to each of its unvisited neighbours (call it D)
// 5. If D < the distance at that node, update the nodes distance from source
// 6. Mark U as visited
// Repeat steps 3-6 until the destination node is reached or till no unvisited vertex is found
// Total Runtime: O(V^2) in current implementation
// Can improve runtime to O(ElogV) using a heap

map<int, int>::iterator it;

void insertEdge(map<int,int>& map, int vertex, int weight) {
    // Check if edge already exists 
    if(map.count(vertex) == 1) {
        // If it does, only insert a new edge it if it's weight is less than the existing edge
        if(weight < map[vertex]) {
            map[vertex] = weight;
        }
    } else {
        map.insert(pair<int, int>(vertex, weight));
    }
}


// Function that implements Dijkstra's algorithm using adjacency list representation of a graph
void dijkstra(vector<map<int,int>>& adjacency_list, int src, int N)
{
    // When the algorithm is finished, dist holds the shortest distance for each node
    int dist[N];   
    bool determined[N] = {false}; 
 
    // Initialize all vertices as an infinite distance away
    for (int i = 0; i < N; i++) {
       dist[i] = INT_MAX;
    }
 
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
 
    // Iterate N-1 times, since each iteration will solve one vertex (and src has already been solved)
    for (int count = 0; count < N-1; count++)
    {
        // Find the Minimum Distance Vertex (mdv) out of the set of remaining undetermined vertices 
        int mdv, min = INT_MAX, min_index;   
        for(int i = 0; i < N; i++) {
            if(determined[i] == false && dist[i] < min) {
                min = dist[i];
                min_index = i;
            }
        }
        // If all the remaining vertices are an "infinite distance" away, then we're done
        if(min == INT_MAX) {
            break;
        }
        mdv = min_index;
        determined[mdv] = true;

        // Iterate over adjacent vertexes of the mdv and update thier distances from src
        for (it = adjacency_list[mdv].begin(); it != adjacency_list[mdv].end(); it++)
        {
            int av = it->first; // av = adjacent vertex
            int weight = it->second;
            // If av hasn't been determined and the path from mdv to av is shorter than it's 
            // current path (distance) from src
            if(!determined[av] && (dist[mdv] + weight) < dist[av]) {
                dist[av] = dist[mdv] + weight;
            }
        }
     }
     // Print the solution
     for(int i = 0; i < N; i++) {
        if(i!=0 && dist[i]!=0) {
            if(dist[i] == INT_MAX) {
                cout<<"-1 ";
            } else {
                cout<<dist[i]<<" ";
            }
        }
     }
    cout<<"\n";
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        if(T < 0) {
            break;
        }
        int N, M, start;
        cin>>N;
        cin>>M;
        // Use an adjacency list to represent the graph (starting from index 1)
        vector<map<int,int>> adjacency_list;
        adjacency_list.resize(N+1);
        for(int i = 0; i < M; i++) {
            int vertex1, vertex2, weight;
            map<int, int> map1, map2;
            cin>>vertex1;
            cin>>vertex2;
            cin>>weight;
            insertEdge(adjacency_list[vertex1], vertex2, weight);
            insertEdge(adjacency_list[vertex2], vertex1, weight);
        }
        cin>>start;
        dijkstra(adjacency_list, start, (N+1));
    }
    return 0;
}