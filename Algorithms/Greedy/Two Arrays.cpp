#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Helper function to sort an array lexicographically decreasing
bool comp(int i, int j) { 
	return i > j; 
}

// Algorithm: Sort the first array lexicographically increasing, the second array lexicographically decreasing
// This will maximize the value of array1[i] + array2[i] for all i, which is what we're after
int main() {
	int T;
	cin>>T;
	while(T > 0) {
		int N, K;
		cin>>N>>K;
		int *array1 = new int[N], *array2 = new int[N];
		for(int i = 0; i < N; i++) {
			cin>>array1[i];
		}
		for(int i = 0; i < N; i++) {
			cin>>array2[i];
		}
		sort(array1, array1+N);
		sort(array2, array2+N, comp);
		bool possible = true;
		for(int i = 0; i < N; i++) {
			if(array1[i] + array2[i] < K) {
				possible = false;
				break;
			}
		}
		if(possible) {
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
		T--;
	}
    return 0;
}
