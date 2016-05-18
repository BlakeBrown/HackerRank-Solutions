#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// We note that misère nim is identical to standard nim, except for when every pile has only
// one stone. In these so called "edge cases", the winner is opposite that of standard nim.

int main() {
	int T;
	cin>>T;
	while(T > 0) {
		int N;
		cin>>N;
		bool pileGreaterThanOne = false;
		int *pile = new int[N]; // pile[i] = # of stones at pile i
		for(int i = 0; i < N; i++) {
			cin>>pile[i];
			if(pile[i] > 1) {
				pileGreaterThanOne = true;
			}
		}
		// Check for edge cases
		if(!pileGreaterThanOne) {
			if(N % 2 == 0) {
				cout<<"First\n";
			} else {
				cout<<"Second\n";
			}
			T--;
			continue;
		}
		// No edge case, so misère nim is the same as standard nim
		int nimSum = pile[0];
		for(int i = 1; i < N; i++) {
			nimSum ^= pile[i];
		}
		if(nimSum != 0) {
			cout<<"First\n";
		} else {
			cout<<"Second\n";
		}
		T--;
	}
    return 0;
}
