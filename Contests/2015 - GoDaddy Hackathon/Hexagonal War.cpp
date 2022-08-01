#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

// Works in 70% of the test cases - almost!!!
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N, moves;
    cin>>N;
    cin>>moves;
    int graph[N][(N*2)-1];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < (N*2)-1; j++) {
            graph[i][j] = 0;
        }
    }
    // Construct graph
    for(int i = 0; i < moves; i ++) {
        int index1, index2;
        cin>>index1;
        cin>>index2;
        index1 -= 1;
        index2 = (index2-1) + index1;
        if(i%2 == 0) {
            // Roman move
            graph[index1][index2] = 1;
        } else {
            // Persian move
            graph[index1][index2] = 2;
        }
    }
    // If graph[x][y] is...
    // 0 = no wall
    // 1 = roman
    // 2 = persian
    list<pair<int,int>> roman_stack, persian_stack;
    bool visited[N][(N*2)-1] = {false};
    for(int i = 0; i < N; i++) {
        if(graph[0][i] == 2) {
            persian_stack.push_front(pair<int,int>(0,i));
        }
        if(graph[i][i] == 1) {
            roman_stack.push_front(pair<int,int>(i,i));
        }
    }
    bool romans = false;
    bool persian = false;
    // DFS to check if romans can build wall
    while(!roman_stack.empty()) {
        // Get the node at the front of the stack and mark it as visited
        pair<int, int> node = roman_stack.front();
        roman_stack.pop_front();
        visited[node.first][node.second] = true;
        // If we reach the right edge, romans can build a wall
        if(node.second == (N+node.first-1)) {
            romans = true;
            break;
        }
        // Check node to the right
        if(graph[node.first][node.second+1] == 1 && !visited[node.first][node.second+1]) {
            roman_stack.push_front(pair<int,int>(node.first, node.second+1));
        }
        // Check node to the left
        if(graph[node.first][node.second-1] == 1 && !visited[node.first][node.second-1]) {
            roman_stack.push_front(pair<int,int>(node.first, node.second-1));
        }
        // Check node above
        if(graph[node.first-1][node.second] == 1 && !visited[node.first-1][node.second]) {
            roman_stack.push_front(pair<int,int>(node.first-1, node.second));
        }
        // Check node below
        if(graph[node.first+1][node.second] == 1 && !visited[node.first+1][node.second]) {
            roman_stack.push_front(pair<int,int>(node.first+1, node.second));
        }
        // Check the 4 diagonals
        if(graph[node.first+1][node.second-1] == 1 && !visited[node.first+1][node.second-1]) {
            roman_stack.push_front(pair<int,int>(node.first+1, node.second-1));
        }   
        if(graph[node.first+1][node.second+1] == 1 && !visited[node.first+1][node.second+1]) {
            roman_stack.push_front(pair<int,int>(node.first+1, node.second+1));
        }   
        if(graph[node.first-1][node.second+1] == 1 && !visited[node.first-1][node.second+1]) {
            roman_stack.push_front(pair<int,int>(node.first-1, node.second+1));
        }   
        if(graph[node.first-1][node.second-1] == 1 && !visited[node.first-1][node.second-1]) {
            roman_stack.push_front(pair<int,int>(node.first-1, node.second-1));
        }   
    }
    // DFS to check if persians can build wall
    while(!persian_stack.empty()) {
        // Get the node at the front of the stack and mark it as visited
        pair<int, int> node = persian_stack.front();
        persian_stack.pop_front();
        visited[node.first][node.second] = true;
        // If we reach the bottom, persians can build a wall
        if(node.first == (N-1)) {
            persian = true;
            break;
        }
        // Check node to the right
        if(graph[node.first][node.second+1] == 2 && !visited[node.first][node.second+1]) {
            persian_stack.push_front(pair<int,int>(node.first, node.second+1));
        }
        // Check node to the left
        if(graph[node.first][node.second-1] == 2 && !visited[node.first][node.second-1]) {
            persian_stack.push_front(pair<int,int>(node.first, node.second-1));
        }
        // Check node above
        if(graph[node.first-1][node.second] == 2 && !visited[node.first-1][node.second]) {
            persian_stack.push_front(pair<int,int>(node.first-1, node.second));
        }
        // Check node below
        if(graph[node.first+1][node.second] == 2 && !visited[node.first+1][node.second]) {
            persian_stack.push_front(pair<int,int>(node.first+1, node.second));
        }
        // Check the 4 diagonals
        if(graph[node.first+1][node.second-1] == 2 && !visited[node.first+1][node.second-1]) {
            persian_stack.push_front(pair<int,int>(node.first+1, node.second-1));
        }   
        if(graph[node.first+1][node.second+1] == 2 && !visited[node.first+1][node.second+1]) {
            persian_stack.push_front(pair<int,int>(node.first+1, node.second+1));
        }   
        if(graph[node.first-1][node.second+1] == 2 && !visited[node.first-1][node.second+1]) {
            persian_stack.push_front(pair<int,int>(node.first-1, node.second+1));
        }   
        if(graph[node.first-1][node.second-1] == 2 && !visited[node.first-1][node.second-1]) {
            persian_stack.push_front(pair<int,int>(node.first-1, node.second-1));
        } 
    }
    if(romans) {
        cout<<"ROMANS";
    } else if(persian) {
        cout<<"PERSIANS";
    } else {
        cout<<"NEITHER";
    }
    return 0;
}