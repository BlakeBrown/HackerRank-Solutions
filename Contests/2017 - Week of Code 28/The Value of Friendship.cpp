#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Unfinished, but here's my best attempt!

unordered_map<int, int> extraQueries; // node -> # of extra queries
unordered_map<int, int> cliqueExtraQueries; // clique -> # of extra queries
unordered_map<int, int> sizeOfClique;
unordered_map<int,int>::iterator it;
unordered_map<int,int>::iterator it2;

struct subset
{
    int parent;
    int rank;
};

// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i)
{
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
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
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    // If ranks are same, then make one as root and increment
    // its rank by one
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int m;
        cin >> n >> m;
        // Allocate memory for creating V sets
        struct subset *subsets = (struct subset*) malloc( n * sizeof(struct subset) );
        
        for (int i = 0; i < n; ++i) {
            subsets[i].parent = i;
            subsets[i].rank = 0;
        }
        
        // // Iterate through all edges of graph, find sets of both
        // // vertices of every edge, if sets are same, then there is
        // // cycle in graph.
        // for(int e = 0; e < E; ++e)
        // {
        //     int x = find(subsets, graph->edge[e].src);
        //     int y = find(subsets, graph->edge[e].dest);
        
        //     if (x == y)
        //         return 1;
        
        //     Union(subsets, x, y);
        // }

        for(int a1 = 0; a1 < m; a1++){
            int node1;
            int node2;
            cin >> node1 >> node2;
            node1 -= 1;
            node2 -= 1;
            cout<<node1<<node2<<"\n";
            int x = find(subsets, node1);
            int y = find(subsets, node2);
            if(x == y ) {
                // Node 1 and Node 2 are already joined
                it = extraQueries.find(node1);
                if(it == extraQueries.end()) {
                    // Key doesn't exist
                    extraQueries[node1] = 1;
                } else {
                    extraQueries[node1]++;
                }
            } else {
                cout<<"union!\n";
                Union(subsets, x, y);
            }
        }

        for(int i = 0; i < n ; i++) {
            cout<<subsets[i].parent<<" ";
            // Node 1 and Node 2 are already joined
            it = sizeOfClique.find(subsets[i].parent);
            if(it == sizeOfClique.end()) {
                // Key doesn't exist
                sizeOfClique[subsets[i].parent] = 1;
            } else {
                sizeOfClique[subsets[i].parent]++;
            }
        }
        cout<<"\n\n";

        for(auto it = extraQueries.begin(); it != extraQueries.end(); it++) {
            cout<<"node: "<<it->first<<" has "<<it->second<<" extra queries\n";
            int clique = subsets[it->first].parent;
            it2 = cliqueExtraQueries.find(clique);
            if(it2 == cliqueExtraQueries.end()) {
                // Key doesn't exist
                cliqueExtraQueries[clique] = 1;
            } else {
                cliqueExtraQueries[clique]++;
            }

        }
        long long answer = 0;
        vector<int> completedCliques;
        for(auto it = sizeOfClique.begin(); it != sizeOfClique.end(); it++) {
            for(int i = 0; i < completedCliques.size(); i++) {
                answer += (completedCliques[i]*completedCliques[i] - completedCliques[i]); 
                // cout<<"Added "<<(completedCliques[i]*completedCliques[i] - completedCliques[i])<<" to answer\n";
            }
            int cliqueSize = it->second;
            if(cliqueSize > 1) {
                cout<<"Clique: "<<it->first<<"\n";
                cout<<"Clique of size: "<<cliqueSize<<", with "<<cliqueExtraQueries[it->first]<<" extra queries\n"; 
            }
            for(int i = 1; i < cliqueSize; i++) {
                answer += (i*i + i);
                // cout<<"Added "<<(i*i + i)<<" to answer\n";
            }
            for(int i = 0; i < cliqueExtraQueries[it->first]; i++) {
                answer += (cliqueSize*cliqueSize - cliqueSize); 
                // cout<<"Added "<<(cliqueSize*cliqueSize - cliqueSize)<<" to answer\n";
            }
            completedCliques.push_back(cliqueSize);
        }
        cout<<answer<<"\n\n\n";
    }
    return 0;
}
