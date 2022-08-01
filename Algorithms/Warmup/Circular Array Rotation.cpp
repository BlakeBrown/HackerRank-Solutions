#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Main algorithm: Use modulo to figure out which indices we need to print without actually
// rotating the array.
int main() {
	// Read input
	int n, k, q;
	cin>>n>>k>>q;
	int *array = new int[n];
	for(int i = 0; i < n; i++) {
		cin>>array[i];
	}
	k %= n; // Remove the number of full array rotations from k
	for(int i = 0; i < q; i++) {
		int b;
		cin>>b;
		cout<<array[(n-k+b)%n]<<"\n"; // Calculate the new index for b
	}
    return 0;
}
