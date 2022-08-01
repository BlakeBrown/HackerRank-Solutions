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
		long long *bricks = new long long[N];
		long long *sum = new long long[N]; // sum[i] = sum of bricks up to i
		for(int i = 0; i < N; i++) {
			cin>>bricks[N-i-1];
		}
		sum[0] = bricks[0];
		for(int i = 1; i < N; i++) {
			sum[i] = sum[i-1] + bricks[i];
		}
		if(N < 4) {
			// Edge case
			cout<<sum[N-1]<<"\n";
			T--;
		} else {
			// Notice that taking Y bricks is equivalent to playing a new game with N-Y bricks where
			// your friend goes first and you start with a score of the sum of the Y bricks.
			long long *dp = new long long[N];
			dp[0] = sum[0];
			dp[1] = sum[1];
			dp[2] = sum[2];
			for(int i = 3; i < N; i++) {
				// Take the # of bricks which maximizes your score
				dp[i] = sum[i] - dp[i-3]; // 3 bricks
				dp[i] = max(dp[i], sum[i] - dp[i-2]); // 2 bricks
				dp[i] = max(dp[i], sum[i] - dp[i-1]); // 1 brick
			}
			cout<<dp[N-1]<<"\n";
			T--;
		}
	}
	return 0;
}

