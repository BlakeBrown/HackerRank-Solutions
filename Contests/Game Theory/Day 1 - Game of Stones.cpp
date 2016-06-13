#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int T;
	cin>>T;
	while(T > 0) {
		int N;
		cin>>N;
		// We can use dynamic programming to compute a solution
		bool *dp = new bool[N+1]; // dp[N] = true -> P1 wins, else P2 wins
		dp[1] = false;
		dp[2] = true;
		dp[3] = true;
		dp[4] = true;
		dp[5] = true;
		for(int i = 6; i <= N; i++) {
			if(dp[i-2] == false || dp[i-3] == false || dp[i-5] == false) {
				dp[i] = true;
			} else {
				dp[i] = false;
			}
		}
		if(dp[N]) {
			cout<<"First\n";
		} else {
			cout<<"Second\n";
		}
		T--;
	} 
    return 0;
}
