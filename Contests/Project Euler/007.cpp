#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

// Useful information to know for future challenges:
// - All primes greater than 3 can be written in the form 6k +/- 1 
// - N can't have a prime factor greater than sqrt(N), unless N itself is prime 
int main() {
    map<int, long> primeMap;
    int count = 1;
    // Sieve of Eratosthenes
    // Generate all primes up to 250,000
    bool* primes = new bool[250000];
    for(long i = 0; i < 250000; i++) {
        primes[i] = true;
    }
    for(long i = 2; i < 500; i++) {
        if(primes[i]) {
            for(long j = (i*i); j < 250000; j+=i) {
                primes[j] = false;
            }
        }
    }
    // Add primes to primeMap
    for(int i = 2; i < 250000; i++) {
        if(primes[i]) {
            primeMap.insert(pair<int, long>(count, i));
            count++;
        }
    }
    int T;
    cin>>T;
    while(T--) {
        int N;
        cin>>N;
        cout<<primeMap[N]<<"\n";
    }
    return 0;
}