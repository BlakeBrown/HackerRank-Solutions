#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

// While this solution works, there is a much more elegant solution I found after reading the editorial.
// If N is even, then we simply need to consider N as a bunch 2*K slots. Solve the problem 
// for each "slot" instead of solving for N directly.
int main() {
	int T;
	cin>>T;
	while(T > 0) {
		long long N, K;
		cin>>N>>K;

		// Algorithm basically reduces down to either an edge case or an outside->inside approach
		if(K == 0) {
			for(long long i = 1; i <= N; i++) {
				cout<<i<<" ";
			}
			cout<<"\n";
			T--;
			continue;
		}
		if(K > N/2 || N%2 == 1) {
			cout<<"-1\n";
			T--;
			continue;
		}

		// *sigh* here we go...
		bool possible = true;
		bool *used = new bool[N+1];
		long long *answer = new long long[N];
		memset(used, false, sizeof(used));
		for(long long i = 1; i <= N/2; i++) {
			// Solve left index
			if(i+K <= N && i-K >= 1) {
				if(!used[i+K] && !used[i-K]) {
					used[i-K] = true;
					answer[i-1] = i-K;
				} else if(!used[i+K] && used[i-K]) {
					used[i+K] = true;
					answer[i-1] = i+K;
				} else if(used[i+K] && !used[i-K]) {
					used[i-K] = true;
					answer[i-1] = i-K;
				} else {
					possible = false;
					break;
				}
			} else if(i+K > N && i-K >= 1) {
				if(!used[i-K]) {
					used[i-K] = true;
					answer[i-1] = i-K;
				} else {
					possible = false;
					break;
				}
			} else if(i+K <= N && i-K <= 1) {
				if(!used[i+K]) {
					used[i+K] = true;
					answer[i-1] = i+K;
				} else {
					possible = false;
					break;
				}
			} else {
				possible = false;
				break;
			}
			// Solve right index
			long long rightIndex = N-i+1;
			if(rightIndex+K <= N && rightIndex-K >= 1) {
				if(!used[rightIndex+K] && !used[rightIndex-K]) {
					used[rightIndex+K] = true;
					answer[rightIndex-1] = rightIndex+K;
				} else if(!used[rightIndex+K] && used[rightIndex-K]) {
					used[rightIndex+K] = true;
					answer[rightIndex-1] = rightIndex+K;
				} else if(used[rightIndex+K] && !used[rightIndex-K]) {
					used[rightIndex-K] = true;
					answer[rightIndex-1] = rightIndex-K;
				} else {
					possible = false;
					break;
				}
			} else if(rightIndex+K > N && rightIndex-K >= 1) {
				if(!used[rightIndex-K]) {
					used[rightIndex-K] = true;
					answer[rightIndex-1] = rightIndex-K;
				} else {
					possible = false;
					break;
				}
			} else if(rightIndex+K <= N && rightIndex-K <= 1) {
				if(!used[rightIndex+K]) {
					used[rightIndex+K] = true;
					answer[rightIndex-1] = rightIndex+K;
				} else {
					possible = false;
					break;
				}
			} else {
				possible = false;
				break;
			}
		}
		// I can start to see why some people may not want to do this for a living...
		if(!possible) {
			cout<<"-1";
		} else {
			for(int i = 0; i < N; i++) {
				cout<<answer[i]<<" ";
			}
		}
		cout<<"\n";
		T--;
	}
    return 0;
}
