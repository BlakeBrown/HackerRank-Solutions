#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Returns the length of the cycle for 1/n
// Note: The largest possible cycle length is n-1, since during long division if we hit a remainder that we've visited before, the cycle will repeat
int lengthOfCycle(int N) {
	int visited[N];
	for(int i = 0; i < N; i++) {
		visited[i] = 0;
	}
	int length = 0;
	long dividend = 10;
	while(dividend != 0) {
		dividend %= N;
		if(visited[dividend]) {
			return length; // cycle repeats!
		}
		visited[dividend] = 1;
		length++;
		dividend *= 10;
	}
	return 0; // no recurring cycle
}


int main() {
	int answer[10000];
	int longestCycle = 3, indexOfLongestCycle = 3;
	for(int i = 3; i < 10000; i++) {
		int cycleLength = lengthOfCycle(i);
		if(cycleLength > longestCycle) {
			longestCycle = cycleLength;
			indexOfLongestCycle = i; 
		}
		answer[i] = indexOfLongestCycle;
	}
	int T;
	cin>>T;
	while(T--) {
		if(T < 0) {
			break;
		}
		int N;
		cin>>N;
		cout<<answer[N-1]<<"\n";
	}
    return 0;
}