#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Use a tail recursion function (return statement at the end of the function) to solve the problem
// in O(pl) time, where p is the # of possible paths Ron/Hermione can take and l is the length of 
// each path. 

// The hardest part to this problem is understanding recursion and how to pass variables by
// reference and by value. See commented code below.

int findPath(char **matrix, bool ***visited, bool &finished, int i, int j, int N, int M, int k) {
	(*visited)[i][j] = true; // Mark the current square as visited so we don't come back to it
	
	// Check if we've reached the destination
	if(matrix[i][j] == '*') {
		finished = true;
		return k;
	}

	// Add 1 to k if Ron/Hermonie can move in more than one direction
	bool canGoDown = i+1 < N && !(*visited)[i+1][j] && matrix[i+1][j] != 'X';
	bool canGoUp = i-1 >= 0 && !(*visited)[i-1][j] && matrix[i-1][j] != 'X';
	bool canGoRight = j+1 < M && !(*visited)[i][j+1] && matrix[i][j+1] != 'X';
	bool canGoLeft = j-1 >= 0 && !(*visited)[i][j-1] && matrix[i][j-1] != 'X';
	int numMoves = 0;
	if(canGoDown) {
		numMoves ++;
	}
	if(canGoUp) {
		numMoves++;
	}
	if(canGoRight) {
		numMoves++;
	}
	if(canGoLeft) {
		numMoves++;
	}
	if(numMoves >= 2) {
		k += 1;
	}

	// Recursively traverse the matrix
	int ans = 0;
	if(canGoDown && !finished) {
		ans = findPath(matrix, visited, finished, i+1, j, N, M, k);
	}
	if(canGoUp && !finished) {
		ans = findPath(matrix, visited, finished, i-1, j, N, M, k);
	}
	if(canGoRight && !finished) {
		ans = findPath(matrix, visited, finished, i, j+1, N, M, k);
	}
	if(canGoLeft && !finished) {
		ans = findPath(matrix, visited, finished, i, j-1, N, M, k);
	}
	return ans;
}

int main() {
	int T;
	cin>>T;
	while(T > 0) {
		int N, M;
		cin>>N>>M;
		T--;
		int startI, startJ;
		char **matrix = new char*[N];
		bool **visited = new bool*[N];
		for(int i = 0; i < N; i++) {
			matrix[i] = new char[M];
			visited[i] = new bool[M];
			for(int j = 0; j < M; j++) {
				cin>>matrix[i][j];
				if(matrix[i][j] == 'M') {
					startI = i;
					startJ = j;
				}
				visited[i][j] = false;
			}
		}
		int K;
		cin>>K;
		bool finished = false;
		// matrix = pass by value
		// visited = pass by reference -> necessary to keep track of visited squares
		// finished = pass by reference -> necessary to keep track of whether or not we finished
		// startI, startJ = pass by value
		// N, M, k = pass by value
		if(findPath(matrix, &visited, finished, startI, startJ, N, M, 0) == K) {
			cout<<"Impressed\n";
		} else {
			cout<<"Oops!\n";
		}
	}
    return 0;
}
