#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

// Returns the number of divisors of n
int countDivisors(long n) {
    long divisors = 0;
    // There can't be any divisors greater than sqrt(n)
    for (long i = 1; i*i <= n; i++) {
        if (n % i == 0) {
        	if(i*i == n) {
        		// Perfect square (ex. 5*5 = 25), only count one divisor
        		divisors += 1;
        	} else {
            	divisors += 2;
        	}
        }
    }
    return divisors;
}

// Summary of algorithm:
// Triangular numbers are of the form T(n) = n(n+1)/2
// After generating a triangular number, we need to find how many divisors it has
// We can calculate the number of divisors in O(sqrt(n)), see countDivisors() --> NOTE: Can improve on this by generating a list primes and using the fact that # of divisors = (# of prime divisor + 1)*(# of prime divisor + 1).. for all prime divisors
// We can also use some math to further optimize: 
// The number of divisors function, sig(n), is multiplicative. i.e sig(mn) = sig(m)*sig(n) if m, n are relatively prime
// This is because if m, n are relatively prime they cannot have any common prime factors (and therefore no common divisors)
// So instead of checking sig(T(n)) or sig((n*(n+1))/2), we can instead check sig(n/2)*sig(n+1) when n is even and sig((n+1)/2)*sig(n) when n is odd
// This DRASTICALLY reduces the number of calculations
// Ex. if n is 1000, instead of checking ~sig(500,000) we check sig(1000) and sig(500) 
int main() {
    int T;
    cin>>T;
    while(T--) {
    	if(T < 0) {
    		break;
    	}
    	int N;
    	cin>>N;
		long long n = 1;
	    while (countDivisors((n+1)/2) * countDivisors(n) <= N) {
	    	// n is even
			n++;
			if (countDivisors(n/2) * countDivisors(n+1) > N) {
				break;
			}
			// n is odd
			n++;
		}
		cout<<(n*(n+1))/2<<"\n";
    }   
    return 0;
}