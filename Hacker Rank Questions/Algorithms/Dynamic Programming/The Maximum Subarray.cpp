#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;


int main() {
	int T, N, max1, max2;
	cin>>T;
	while(T > 0) {
		// Read input
		cin>>N;
		int *A = new int[N];
		for(int i = 0; i < N; i++) {
			cin>>A[i];
		}
		max1 = INT_MIN; // Smallest contiguous subarray
		max2 = INT_MIN; // Smallest non-contiguous subarray
		// To find the max2, either
		// a) Add up all positive numbers 
		// or b) If there are no positive numbers, take the smallest negative number
		bool foundPositive = false;
		for(int i = 0; i < N; i++) {
			if(max2 > 0) {
				foundPositive = true;
			}
			if(max2 > 0 && A[i] > 0) {
				max2 += A[i];
			} else if(max2 < 0 && A[i] > max2) {
				max2 = A[i];
			}
		}
		// To find the max1, use DP if there's at least 1 positive number
		if(foundPositive) {		
			for(int i = 1; i < N; i++) {
				if(A[i-1] + A[i] > 0) {
					A[i] = A[i-1] + A[i];
				} else {
					A[i] = 0;
				}
			}
		} else {
			// Otherwise max1 is just the smallest negative number, same as max2
			max1 = max2;
		}
		// Now the largest value in the array is our max
		for(int i = 0; i < N; i++) {
			if(A[i] > max1) {
				max1 = A[i];
			}
		}
		cout<<max1<<" "<<max2<<"\n";
		T--;
	}
    return 0;
}
