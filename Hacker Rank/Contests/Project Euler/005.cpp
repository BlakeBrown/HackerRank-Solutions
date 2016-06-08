#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Problem requires Fundamental Theorem of Arithmetic and some careful thinking
int main() {
    // Precalculate all of the primes up to 40 (could use Sieve of Eratosthenes for larger N)
    int primes[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    int T;
    cin>>T;
    while(T--) {
        if(T < 0) {
            break;
        }
        int N;
        cin>>N;
        // Special case
        if(N == 1) {
            cout<<1<<"\n";
            continue;
        }
        long long answer = 1;
        // Summary of Algorithm:
        // For every prime up to N, find out how many of those primes fit within N
        // Our answer is then each prime * how many times it fits within N
        // Ex: 10
        // Answer = 2^3 * 3^2 * 5 * 7
        // Why does this work?
        // 2^3 allows us to make 2, 4 and 8
        // 3^2 allows us to make 3 and 9
        // We have primes 5 and 7
        // Using the previous: 2*3 allows us to make 6, 2*5 allows us to make 10
        for(int i = 0; i < 12; i++) {
            int j = primes[i];
            if(j <= N) {
                while(true) {
                    if(j*primes[i] > N) {
                        break;
                    }
                    j *= primes[i];
                } 
                answer *= j;
            }
        }
        cout<<answer<<"\n";
    }
    return 0;
}