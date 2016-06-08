#include <cmath>
#include <cstdio>
#include <list>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

map<long,int>::iterator it;

// Returns the sum of proper divisors of N
// This is useful: https://en.wikipedia.org/wiki/Divisor_function
// Note the difference between sig[0] (number of divisors), sig[1] (sum of all divisors) and s (sum of all proper divisors) -> all of which are determinable by prime factorization
int sumProperDivisors(long N) { 
    long tempN = N;
    if(N == 1) {
        return 0;
    }
    if(N == 2) {
        return 1;
    }
    // Map: prime factor -> number of that factor (exponent)
    // i.e 2^5: 2 -> 5
    map<long,int> primeFactors;
    while(N != 1) {
        bool prime = true;
        // Since 2 is the only even prime, check for it first so we can increment by 2 in the next loop
        if(N%2 == 0) {
            prime = false;
            it = primeFactors.find(2);
            if(it == primeFactors.end()) {
                // Not in map
                primeFactors.insert(pair<long, int>(2, 1));
            } else {
                // In map
                primeFactors[2] = it->second + 1;
            }
            N /= 2;
            continue;
        }
        for(long long i = 3; i*i <= N; i+=2) {
            if(N % i == 0) {
                it = primeFactors.find(i);
                if(it == primeFactors.end()) {
                    // Not in map
                    primeFactors.insert(pair<long, int>(i, 1));
                } else {
                    // In map
                    primeFactors[i] = it->second + 1;
                }
                N /= i;
                prime = false;
                break;
            }
        }
        if(prime) {
            // There's no prime factor less than sqrt(N), so N itself is prime
            it = primeFactors.find(N);
            if(it == primeFactors.end()) {
                primeFactors.insert(pair<long, int>(N, 1));
            } else {
                primeFactors[N] = it->second + 1;
            }
            break;
        }
    }
    long sum = 1;
    for(it = primeFactors.begin(); it != primeFactors.end(); it++) {
        long factor = it->first;
        int exponent = it->second;
        // We can use the prime factors in order to get the sum of proper divisors
        // See: http://math.stackexchange.com/questions/22721/is-there-a-formula-to-calculate-the-sum-of-all-proper-divisors-of-a-number
        long tempSum = 0, multiplier = 1;
        for(int i = 0; i <= exponent; i++) {
            tempSum+=multiplier;
            multiplier*=factor;
        }
        sum*=tempSum;
    }
    return sum-tempN;
}

int main() {
    // Precompute the sum of proper divisors of n into an array
    // i.e array[10] = 1 + 2 + 5 = 8
    long* array = new long[100001];
    for(int i = 1; i <= 100000; i++) {
       array[i] = sumProperDivisors(i);
   }
    list<long> amicableNumbers;
    // Precompute amicable numbers
    for(long a = 1; a <= 100000; a++) {
        long b = array[a];
        if(b <= 100000 && a!=b && a == array[b]) {
            amicableNumbers.push_back(a);
        }
    }
    int T;
    cin>>T;
    while(T--) {
        if(T < 0) {
            break;
        }
        long N, sum = 0;
        cin>>N;
        for(auto it = amicableNumbers.begin(); it != amicableNumbers.end(); ++it) {
            long amicableNumber = *it;
            if(amicableNumber >= N) {
                break;
            } else {
                sum+=amicableNumber;
            }
        }
        cout<<sum<<"\n";
    } 
    return 0;
}