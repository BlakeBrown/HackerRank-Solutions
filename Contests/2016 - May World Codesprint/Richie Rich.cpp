#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	string s;
	long long n, k;
	cin>>n>>k>>s;

	// Corner cases
	if(n == 1) {
		if(k > 0) {
			cout<<9;
		} else {
			cout<<s;
		}
		return 0;
	}


    bool possible = true;
	bool *changed = new bool[n];
	for(long long i = 0; i < n; i++) {
		changed[i] = false;
	}
	// Start by fixing any unmatching indices to make s a palindrome
	for(long long i = 0; i < s.size()/2; i++) {
		if(s[i] != s[s.size()-i-1]) {
			if(k > 0) {
				if(s[i] > s[s.size()-i-1]) {
					s[s.size()-i-1] = s[i];
					changed[s.size()-i-1] = true;
				} else {
					s[i] = s[s.size()-i-1];
					changed[i]= true;
				}
				k--;
			} else {
				possible = false;
			}
		}
	}
	// Check if we were unable to make s a palindrome
	if(!possible) {
		cout<<"-1";
		return 0;
	}
	// Now we make s the "optimal" palindrome
	// Change indices to 9s as long k is large enough
	for(long long i = 0; i < s.size()/2; i++) {
		if(k == 0) {
			break;
		}
		if(s[i] != '9') {
			if(changed[i] || changed[s.size()-i-1]) {
				// Only need k=1 to make both 9's
				s[i] = '9';
				s[s.size()-i-1] = '9';
				k--;
			} else {
				// Need k = 2
				if(k >= 2) {
					s[i] = '9';
					s[s.size()-i-1] = '9';
					k-=2;
				}
			}
		}
	}
	// If n is odd, we also have to worry about a corner case where we can change the middle digit to a 9
	if(n%2 == 1 && k>=1) {
		s[n/2] = '9';
	}
	cout<<s<<"\n";
    return 0;
}
