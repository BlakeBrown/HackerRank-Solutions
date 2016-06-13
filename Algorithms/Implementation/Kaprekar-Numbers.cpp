#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool kaprekar(long long x) {
	// Corner cases for numbers that have a single digit when squared
	if(x == 0) {
		return true;
	}
	if(x == 1) {
		return true;
	}
	if(x == 2) {
		return false;
	}
	if(x == 3) {
		return false;
	}
	long long x_squared = x*x;
	string x_squared_string = to_string(x*x);
	string part1, part2;
	for(long long i = 0; i < x_squared_string.length()/2; i++) {
		part1 += x_squared_string[i];
	}
	for(long long i = x_squared_string.length()/2; i < x_squared_string.length(); i++) {
		part2 += x_squared_string[i];
	}
	if(stoll(part1) + stoll(part2) == x) {
		return true;
	} else {
		return false;
	}
}

int main() {
    long long p, q;
    cin>>p>>q;
    for(long long i = p; i < q; i++) {
    	if(kaprekar(i)) {
    		cout<<i<<" ";
    	}
    }
    return 0;
}