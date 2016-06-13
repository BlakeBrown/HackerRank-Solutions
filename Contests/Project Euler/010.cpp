#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	// Use Sieve of Eratosthenes to generate primes up to 10^6
	// We can use dynamic programming at the same time to keep track of the sum
	bool* primes = new bool[1000001];
	long long array[1000001];
	long long sum = 0;
	array[1] = 0;
	for(long i = 0; i < 1000001; i++) {
	    primes[i] = true;
	}
	for(long i = 2; i < 1000001; i++) {
	    if(primes[i]) {
	    	sum+=i;
	        for(long j = (i*i); j <= 1000000; j+=i) {
	            primes[j] = false;   
	        }
	    }
	    array[i] = sum;
	} 
    int T;
    cin>>T;
    while(T--) {
    	if(T < 0) {
    		break;
    	}
    	int N;
    	cin>>N;
    	cout<<array[N]<<"\n";
    }
    return 0;
}