#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// LCS is a common dynamic programming problem that is solveable in O(n*m) time and space,
// where n is the length of the first string and m is the length of the second string.

// To realize why dynamic programming is required, we first check that the problem 
// has an optimal substructure, in other words it can be broken down into simpler subproblems.
// Observing two strings "abcdaf" and "acbcf", we notice two properties:
// 1. If the letter at a given index is the SAME in both strings then clearly that letter must be 
// part of the LCS. For example we can see that the first letter 'a' should be included in the LCS.
// 2. If the letter at a given index is DIFFERENT in both strings, then we take the max of 
// LCS(string1-letter, string2) and LCS(string1, string2-letter). For example the second letter 
// is different in both strings, so we take max(LCS("acdaf","acbcf"), LCS("abcdaf","abcf"))

// In order to use DP, we simply create an n*m array where array[i][j] is the LCS
// of string1.substr(0, i) and string2.substr(0,j). Iterating over the array, we set
// array[i][j] to array[i-1][j-1] + 1 if letters i and j are the same, otherwise we 
// set array[i][j] to max(array[i-1][j], array[i][j-1]) if letters i and j are the different.
// This takes O(n*m) time and follows the optimal substructure we described above.

// Lastly, here's a great video describing this approach: https://www.youtube.com/watch?v=NnD96abizww
int main() {
	// Read input
	int n, m;
	cin>>n>>m;
	int *array1 = new int[n];
	int *array2 = new int[m];
	for(int i = 0; i < n; i++) {
		cin>>array1[i];
	}
	for(int i = 0; i < m; i++) {
		cin>>array2[i];
	}
	// Setup DP 
	int **matrix = new int*[n+1];
	for(int i = 0; i <= n; i++) {
		matrix[i] = new int[m+1];
		for(int j = 0; j <= m; j++) {
			matrix[i][j] = 0;
		}
	}
	// Main algorithm
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(array1[i-1] == array2[j-1]) {
				// Property 1
				matrix[i][j] = matrix[i-1][j-1] + 1;
			} else {
				// Property 2
				matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1]);
			}
		}
	}
	// Read off solution, size of lcs is matrix[n][m]
	int *lcs = new int[matrix[n][m]];
	int count = matrix[n][m];
	int i = n, j = m;
	while(count > 0) {
		if(matrix[i-1][j] == matrix[i][j]) {
			// Value came from smaller array1
			i--;
		} else if(matrix[i][j-1] == matrix[i][j]) {
			// Value came from smaller array2
			j--;
		} else {
			// Value came from the letter at the current index
			lcs[count-1] = array1[i-1];
			i--;
			j--;
			count--;
		}
	}
	for(int i = 0; i < matrix[n][m]; i++) {
		cout<<lcs[i]<<" ";
	}
    return 0;
}
