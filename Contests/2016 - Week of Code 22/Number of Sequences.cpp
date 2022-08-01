#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int,int> map; // number -> prime factor
unordered_map<int,int>::iterator it;

// Determines an indices contribution to the number of "nice sequences"
int determineContribution(int x) {
	it = map.find(x);
	if(it == map.end()) {
		return 1; // x isn't composed of a single prime factor
	} else {
		return it->second;
	}
}

int main() {
	// Use Sieve of Eratosthenes to generate a list of primes up to N: 
	// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
	bool* prime = new bool[100000];
	// Initialize array
	for(long long i = 0; i < 100000; i++) {
	    prime[i] = true;
	}
	// Perform sieve
	for(long long i = 2; i*i < 100000; i++) {
	    if(prime[i]) {
	        for(long long j = i*i; j < 100000; j+=i) {
	            prime[j] = false;
	        }
	    }
	}
	// Add primes to map
	int var = 2;
	while(var < 100000) {
		map.insert(pair<int,int>(var,2));
		var *= 2;
	}
	for(int i = 3; i < 100000; i+=2) {
	    if(prime[i]) {
	    	for(int j = i; j < 100000; j*=i) {
	    		map.insert(pair<int,int>(j,i));
	    	}
	    }
	}

	int n;
	cin>>n;
	int *input = new int[n], *a = new int[n]; // a[i] = required mod value for index i, -1 if there is none
	for(int i = 0; i < n; i++) {
		cin>>input[i];
		a[i] = -1;
	}
	for(int i = 1; i < n; i++) {
		int k = i+1;
		for(int j = i; j < n; j += k) {
			if(input[j] != -1) {
				if(a[k-1] == -1) {
					a[k-1] = input[j]%k;
				} else if(input[j]%k != a[k-1]) {
					// Invalid array
					cout<<"0";
					return 0;
				}
			}
		}
	}
	long long answer = 1;
	for(int i = 0; i < n; i++) {
		if(a[i] == -1) {
			answer *= determineContribution(i+1);
			answer %= 1000000007;
		}
	}
	cout<<answer;
    return 0;
}
