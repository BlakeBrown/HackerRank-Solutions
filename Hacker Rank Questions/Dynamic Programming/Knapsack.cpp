#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

// Very similar to the coin change problem, we want to know if we can build a number or not
int main() {
	int T, n, k; // k = expected sum
	cin>>T;
	while(T > 0) {
		cin>>n>>k;
		int *a = new int[n]; // a = integers we have
		bool *buildable = new bool[k+1]; // buildable = integers we can make
		for(int i = 0; i < n; i++) {
			cin>>a[i];
		}
		memset(buildable, 0, sizeof(buildable));
		buildable[0] = 1; // Don't use any integers to build zero
		bool corner_case = 0;
		// Optimization 1: If k is a multiple of any of our integers, or if we have a 1, we can trivially build k
		for(int i = 0; i < n; i++) {
			if(k%a[i] == 0 || a[i] == 1) {
				cout<<k<<"\n";
				corner_case = 1;
				break;
			}
		}
		if(corner_case) {
			T--;
			continue;
		}
		// Optimization 2: We use a standard DP approach, except we break after each loop if we've found a way to form k
		for(int i = 0; i < n; i++) {
			for(int j = 0; j + a[i] <= k; j++) {
				if(buildable[j]) {
					buildable[j + a[i]] = 1;
				}
			}
			if(buildable[k]) {
				break;
			}
		}
		bool builtInt = false;
		for(int i = k; i >= 0; i--) {
			if(buildable[i]) {
				// We can build i, which is the closest we can get to k
				cout<<i<<"\n";
				builtInt = true;
				break;
			}
		}
		if(!builtInt) {
			cout<<"0\n";
		}
		T--;
	}
    return 0;
}
