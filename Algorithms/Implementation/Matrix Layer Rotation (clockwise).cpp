#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Main algorithm: in order to rotate the whole matrix, we'll just rotate one ring at a time
// We can do this in-place to achieve O(1) additional space complexity
int main() {
	int M, N, R;
	cin>>M>>N>>R;
	int **matrix = new int*[M];
	for(int i = 0; i < M; i++) {
		matrix[i] = new int[N];
		for(int j = 0; j < N; j++) {
			cin>>matrix[i][j];
		}
	}

	int numRings = min(M,N)/2;
	for(int i = 0; i < numRings; i++) {
		// Subtract the number of 360 degree rotations from R
		// A 360 degree rotation = rotating the same number of times as the perimeter of the current ring
		int numRotations = R%(2*(M + N - 4*i) - 4);
		for(int rotation = 0; rotation < numRotations; rotation++) {
			// Rotate the current ring:
			// - In order to not use additional memory, we'll just swap elements
			// - We need to repeatedly swap the last element in the top row until it becomes the first element
			// - Then we need to swap that element down to the bottom of the left column
			// - Then we need to swap that element over to the bottom of the right column
			// - Then we need to swap that element to the 2nd highest element in the right column
			// - Then the ring will be rotated! See an example below:

			// Let's rotate the outer-most ring on the following 4x4 matrix (hint: follow the '4')
			// 1 2 3 4
			// 5 6 7 8
			// 9 10 11 12
			// 13 14 15 16

			// Iteration 1
			// 4 1 2 3
			// 5 6 7 8
			// 9 10 11 12
			// 13 14 15 16

			// Iteration 2
			// 5 1 2 3
			// 9 6 7 8
			// 13 10 11 12
			// 4 14 15 16


			// Iteration 3
			// 5 1 2 3
			// 9 6 7 8
			// 13 10 11 12
			// 14 15 16 4


			// Iteration 4 - finished, the outer ring is rotated!
			// 5 1 2 3
			// 9 6 7 4
			// 13 10 11 8
			// 14 15 16 12

			// Rotate top row
			for(int j = N-i-1; j > i; j--) {
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[i][j-1];
				matrix[i][j-1] = tmp;
			}
			// Rotate left column
			for(int j = i; j < M-i-1; j++) {
				int tmp = matrix[j][i];
				matrix[j][i] = matrix[j+1][i];
				matrix[j+1][i] = tmp;
			}
			// Rotate bottom row
			for(int j = i; j < N-i-1; j++) {
				int tmp = matrix[M-i-1][j];
				matrix[M-i-1][j] = matrix[M-i-1][j+1];
				matrix[M-i-1][j+1] = tmp;
			}
			// Rotate right column
			for(int j = M-i-1; j > i+1; j--) {
				int tmp = matrix[j][N-i-1];
				matrix[j][N-i-1] = matrix[j-1][N-i-1];
				matrix[j-1][N-i-1] = tmp;
			}
		}
	}
	// Output final matrix
	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			cout<<matrix[i][j]<<" ";
		}
		cout<<"\n";
	}
    return 0;
}

// Additional info: A faster algorithm (same time complexity, but lower constant factor) exists 
// for rotating matrices by 90 degrees (extendable to 180, 270, etc). Simply transpose the 
// matrix then swap every left column with its matching right column.
// i.e To rotate a 3x3 matrix by 90 degrees, transpose the matrix than swap column 1 with column 3
