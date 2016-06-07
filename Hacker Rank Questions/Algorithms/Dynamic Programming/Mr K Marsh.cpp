#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int m, n;
	cin>>m>>n;
	bool **land = new bool*[m];
	// left[i][j] gives how many spaces you can go left from point (i,j), etc.
	int **left = new int*[m], **right = new int*[m], **up = new int*[m], **down = new int*[m];
	// Use DP to calculate left, right, up, down matrices
	for(int i = 0; i < m; i++) {
		land[i] = new bool[n];
		left[i] = new int[n];
		right[i] = new int[n];
		up[i] = new int[n];
		down[i] = new int[n];
		int spaces = 0;
		for(int j = 0; j < n; j++) {
			char c;
			cin>>c;
			if(c == 46) {
				land[i][j] = true;
				left[i][j] = spaces++;
			} else {
				land[i][j] = false;
				left[i][j] = -1;
				spaces = 0;
			}
		}
	}
	// Calc right matrix
	for(int i = 0; i < m; i++) {
		int spaces = 0;
		for(int j = n-1; j >= 0; j--) {
			if(land[i][j]) {
				right[i][j] = spaces++;
			} else {
				right[i][j] = -1;
				spaces = 0;
			}
		}
	}
	// Calc up matrix
	for(int i = 0; i < n; i++) {
		int spaces = 0;
		for(int j = 0; j < m; j++) {
			if(land[j][i]) {
				up[j][i] = spaces++;
			} else {
				up[j][i] = -1;
				spaces = 0;
			}
		}
	}
	// Calc down matrix
	for(int i = 0; i < n; i++) {
		int spaces = 0;
		for(int j = m-1; j >= 0; j--) {
			if(land[j][i]) {
				down[j][i] = spaces++;
			} else {
				down[j][i] = -1;
				spaces = 0;
			}
		}
	}

	// Main algorithm: Note that we only need two corners to form a rectangle. If we iterate
	// over all the points in the matrix taking O(mn) time, we just need to check all the possible
	// rectangles that can be formed using each point. Since we've already calculated left, right,
	// up, down matrices, this makes it very easy to check which rectangles can be formed.
	// Overall runtime: O(n*m*k) where k is the number of possible rectangles for each point

	int maxPerimeter = 0;
	// Step 1: Iterate over the matrix
	for(int i = 0; i < m-1; i++) {
		for(int j = 0; j < n-1; j++) {
			// Optimization - Continue if we can't make a rectangle
			if(!land[i][j]) {
				continue;
			}
			// Step 2: For each point, iterate over all the possible points that could form a rectangle
			for(int x = i+down[i][j]; x >= i+1; x--) {
				for(int y = j+right[i][j]; y >= j+1; y--) {
					int side1 = y-j;
					int side2 = x-i;
					// Optimization - Break if we can't make a larger rectangle
					if(side1 + side2 <= maxPerimeter) {
						break;
					}
					// Step 3: Check if we can make a rectangle
					if(land[x][y] && left[x][y] >= side1 && up[x][y] >= side2) {			
						if(side1 + side2 > maxPerimeter) {
							maxPerimeter = side1 + side2;
						}
					}
				}
			}
		}
	}
	if(maxPerimeter == 0) {
		cout<<"impossible\n";
	} else {
		cout<<maxPerimeter*2<<"\n";
	}
    return 0;
}
