#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	// Construct nCr table before doing test cases
    // We can do this using DP in O(n^2) time, where n is the max value of nCr. We basically
    // start with the first row of Pascals triangle, and build each of the following rows using 
    // the previous one. This way our queries take O(1) time.
    
    // Initialize table
    long long **table = new long long*[1000];
    for(int i = 0; i < 1000; i++) {
    	table[i] = new long long[1001];
    	for(int j = 0; j < 1001; j++) {
    		table[i][j] = 0;
    	}
    }

    // Build table
    table[0][0] = 1;
    table[0][1] = 1;
    for(int i = 1; i < 1000; i++) {
    	table[i][0] = 1;
    	for(int j = 1; j < i+1; j++) {
    		table[i][j] = (table[i-1][j-1] + table[i-1][j])%1000000000;
    	}
    	table[i][i+1] = 1;
    }

    // Perform queries
    int T;
    cin>>T;
    while(T > 0) {
    	int n;
    	cin>>n;
		for(int i = 0; i <= n; i++) {
			cout<<table[n-1][i]<<" ";
		}
		cout<<"\n";
    	T--;
    }
    return 0;
}
