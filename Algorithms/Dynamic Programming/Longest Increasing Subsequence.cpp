#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// We can take a DP approach by starting at the beginning of the array, and improving upon
// our subsequences every time we reach a new element. There's a great description of this approach
// here: http://stackoverflow.com/questions/2631726/how-to-determine-the-longest-increasing-subsequence-using-dynamic-programming/2631810#2631810

// Array: 2 6 3 4 1 2 9 5 8

// Steps:

// 0. S = {} - Initialize S to the empty set
// 1. S = {2} - New largest LIS
// 2. S = {2, 6} - New largest LIS
// 3. S = {2, 3} - Changed 6 to 3
// 4. S = {2, 3, 4} - New largest LIS
// 5. S = {1, 3, 4} - Changed 2 to 1
// 6. S = {1, 2, 4} - Changed 3 to 2
// 7. S = {1, 2, 4, 9} - New largest LIS
// 8. S = {1, 2, 4, 5} - Changed 9 to 5
// 9. S = {1, 2, 4, 5, 8} - New largest LIS
// Note that S array DOES NOT represent the actual subsequence. 
// S[i] is the smallest integer that ends an increasing sequence of length i

int main() {
	int N;
	cin>>N;
	int *input = new int[N];
	vector<int> lis; // lis[i] = the last value in the longest increasing subsequence (lis) of length i
	for(int i = 0; i < N; i++) {
		cin>>input[i];
	}

	// Main algorithm
	lis.push_back(input[0]);
	for(int i = 1; i < N; i++) {
		int upperBoundIndex = (upper_bound(lis.begin(), lis.end(), input[i]) - lis.begin());
		if(upperBoundIndex == lis.size()) {
			// Additional check to deal with the "strictly increasing" condition 
			if(input[i] > lis[lis.size()-1]) {
				lis.push_back(input[i]);
			}
		} else {
			if(upperBoundIndex == 0) {
				lis[upperBoundIndex] = input[i];
			}
			// Additional check to deal with the "strictly increasing" condition 
			if(input[i] > lis[upperBoundIndex-1]) {
				lis[upperBoundIndex] = input[i];
			}
		}
	}
	cout<<lis.size();
    return 0;
}
