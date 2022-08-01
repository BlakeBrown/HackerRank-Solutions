#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// We can use dynamic programming to calculate sumLeft[i] and sumRight[i] in O(n) time
// Then we just iterate over the list and compare indices
// Overall runtime: O(n)

int main() {
	int T;
	cin>>T;
	while(T > 0) {
		int N;
		cin>>N;
		int *A = new int[N], *sumLeft = new int[N], *sumRight = new int[N];
		cin>>A[0];
		sumLeft[0] = 0;
		sumRight[N-1] = 0;
		for(int i = 1; i < N; i++) {
			cin>>A[i];
			sumLeft[i] = sumLeft[i-1] + A[i-1];
		}
		for(int i = N-2; i >= 0; i--) {
			sumRight[i] = sumRight[i+1] + A[i+1];
		}
		bool exists = false;
		for(int i = 0; i < N; i++) {
			if(sumLeft[i] == sumRight[i]) {
				exists = true;
				break;
			}
		}
		if(exists) {
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
		T--;
	}
    return 0;
}
