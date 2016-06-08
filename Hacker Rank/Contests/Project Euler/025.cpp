#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long double phi = (1+sqrt(5))/2;

long double logBase(long double base, long double n) {
	return log(n)/log(base);
}

// Returns the first term in the fibonacci sequence to contain N digits (for large N)
int smallestFibTerm(int numDigits) {
	long double result = (numDigits-1)*logBase(phi,10) + logBase(phi, sqrt(5));
	return ceil(result);
}

// Explanation:
// Binet's formula to calculate the nth fibonacci number is: Fib(n) = (Phi^n - (-phi)^-n)/sqrt(5)
// Since (-phi)^-n approaches 0 as n->infinity, we can say Fib(n) ~= (phi^n)/sqrt(5) for large n
// To get the number of digits, we require the first Fib(n) > 10^(numDigits-1)
// Solve the inequality: 
// (phi^n)/sqrt(5) > 10^(numDigits-1)
// log[phi](phi^n) - log[phi](sqrt(5)) > log[phi](10^numDigits-1)
// n = ceil((numDigits-1)*log[phi](10) + log[phi](sqrt(5)))
int main() {
	int T;
	cin>>T;
	while(T--) {
		if(T < 0) {
			break;
		}
		int N;
		cin>>N;
		cout<<smallestFibTerm(N)<<"\n";		
	}
    return 0;
}