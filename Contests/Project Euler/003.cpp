#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Finds the largest prime factor of N
int main() {
    int T;
    cin>>T;
    while(T--) {
        if(T < 0) {
            break;
        }
        long long N;
        cin>>N;
        long long largest_prime_factor = 1;
        // Summary of Algorithm: 
        // We iterate from 2 to sqrt(N) and look for the first number that divides N
        // We divide N by that number and repeat till N = 1
        // If we don't find any number that divides N, then that means N is prime
        // Why does this work? 
        // Consider 30: 
        // 30/2 = 15
        // 15/3 = 5
        // 5/5 = 1, so 30's largest prime factor is 5
        // Somewhat unintuitively, it is actually guaranteed that each number we divide N by is also prime
        // First recall that every number is either prime or is the product of prime numbers (fundamental theorem of arithmetic)
        // Thus by iterating from 2, we are guaranteed to always hit a prime before a composite number since 
        // composite numbers are by definition COMPOSED of primes
        // Since we are essentially eliminating the prime factors in increasing order, the last prime factor will be the largest
        // Why do we only iterate to sqrt(N)? 
        // Because there can be no prime factor of N that is larger than sqrt(N) (other than N itself)
        while(N != 1) {
            bool found = false;
            for(long long i = 2; i <= (long long) sqrt((double)N); i++) {
                if(N % i == 0) {
                    largest_prime_factor = i;
                    N /= i;
                    found = true;
                    break;
                }
            }
            if(!found) {
                // There's no prime factor less than sqrt(N), so N itself is prime
                largest_prime_factor = N;
                break;
            }
        }
        cout<<largest_prime_factor<<"\n";
    }
    return 0;
}