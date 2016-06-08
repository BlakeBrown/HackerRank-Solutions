#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

set<int>::const_iterator pos;

int main() {
    int T;
    cin>>T;
    while(T--) {
        if(T < 0) {
            break;
        }
        int N, M;
        cin>>N;
        cin>>M;
        // Use an adjacency list to represent the graph (starting from index 1)
        vector<set<int>> adjacency_list;
        adjacency_list.resize(N+1);
        for(int i = 0; i < M; i++) {
            int vertex1, vertex2;
            cin>>vertex1;
            cin>>vertex2;
            adjacency_list[vertex1].insert(vertex2);
            adjacency_list[vertex2].insert(vertex1);
        }
        bool visited[N+1] = {false};
        int distance[N+1] = {0};
        list<int> queue; 
        int start;
        cin>>start;
        // Add the starting vertex to the queue
        queue.push_back(start);
        visited[start] = true;
        // BREADTH-FIRST TRAVERSAL :)
        while(!queue.empty()) {
            // Grab the first node in the queue
            int node = queue.front();
            // Add all of the node's children to the queue
            for(pos = adjacency_list[node].begin(); pos != adjacency_list[node].end(); ++pos) {
                if(!visited[*pos]) {
                    queue.push_back(*pos);
                    // Distance is that of the parent node + an extra edge
                    // Remember: Since the graph is undirected, it means that as soon as we visit a node in a breadth-first 
                    // traversal, we immediately know the distance from the origin to the node
                    distance[*pos] += (distance[node] + 6);
                    visited[*pos] = true;
                }
            } 
            // Remove node from queue
            queue.pop_front();
        }
        for(int i = 1; i <= N; i++) {
            if(i != start) {
                if(distance[i] == 0) {
                    cout<<"-1 ";
                } else {
                    cout<<distance[i]<<" ";
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}