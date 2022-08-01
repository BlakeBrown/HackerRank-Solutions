#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	long long n;
	cin>>n;
	long long *x = new long long[n], *y = new long long[n];
	long long sumX = 0, sumY = 0;
	for(int i = 0; i < n; i++) {
		cin>>x[i];
		sumX += x[i];
	}
	for(int i = 0; i < n; i++) {
		cin>>y[i];
		sumY += y[i];
	}
	sort(x, x+n);
	sort(y, y+n);
	// Edge case: We can never change the sum of either set, so if the sums 
	// are different it's impossible to solve.
	if(sumX != sumY) {
		cout<<"-1";
		return 0;
	}
	// Otherwise we just have to consider the difference between elements in set x and
	// elements in set y. If x[i] - y[i] is positive, then we can fix it with a 
	// negative x[j]-y[j] at another index. Thus we just have to sum all of the 
	// positive (or negative) delta values for every index.
	long long answer = 0;
	for(int i = 0; i < n; i++) {
		long long diff = x[i] - y[i];
		if(diff > 0) {
			answer += diff;
		}
	}
	cout<<answer;
    return 0;
}
