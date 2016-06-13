#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Cool problem! Trick is to realize that each tower is really a nim heap of size # of prime factors

int main() {
    int T;
    cin>>T;
    while(T > 0) {
        int N;
        cin>>N;
        long tmp, nimSum = 0;
        for(int i = 0; i < N; i++) {
            cin>>tmp;
            // Determine number of prime factors
            int numPrimeFactors = 0;
            if(tmp == 1) {
                numPrimeFactors = 0;
            } else if(((tmp != 0) && !(tmp & (tmp - 1)))) {
                // If tmp is a power of 2
                numPrimeFactors = tmp/2;
            } else {
                // Calculate # of prime factors
                while(tmp > 1) {
                    bool foundFactor = false;
                    for(long j = 2; j*j <= tmp; j++) {
                        if(tmp%j == 0) {
                            numPrimeFactors++;
                            tmp /= j;
                            foundFactor = true;
                            break;
                        }
                    }
                    if(!foundFactor) {
                        // tmp is prime
                        numPrimeFactors++;
                        break;
                    }
                }
            }
            nimSum ^= numPrimeFactors;
        }
        if(nimSum != 0) {
            cout<<"1\n";
        } else {
            cout<<"2\n";
        }
        T--;
    }
    return 0;
}
