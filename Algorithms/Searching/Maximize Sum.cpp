#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


set<long long>::iterator it;

// A tricky question! Lots of possible algorithms, but due to strict runtime conditions/testcases
// you need to optimize as much as possible.

// Start by noticing that since (A+B)%M = (A%M + B%M)%M, so we can compute the prefixSum (the sum 
// of the elements up to [i] % M) very quickly by using % as we go along. Using this trick, we can
// quickly come up with an O(n^2) algorithm as follows:
// ... read input and create prefixSum[]
//  long long maxSumModM = prefixSum[0];
//  for(long long i = 1; i <= N; i++) {
//		for(long long j = i-1; j >= 0; j--) {
//			Note: We need to add M to deal with negative numbers
//  	   	long long sumModM = (prefixSum[i] - prefixSum[j] + M)%M;
// 			if(sumModM > maxSumModM) {
// 				maxSumModM = sumModM;
// 			}
// 		}
//  	maxSumModM = max(maxSumModM, prefixSum[i]);
//  }

// However, unfortunately this isn't fast enough to pass all the test cases :( 
// Let's see if we can do better, we'll make use of 2 observations.

// 1. Notice that if we were to use the code above, sumModM ≤ prefixSum[i] whenever 
// prefixSum[j] ≤ prefixSum[i]. This is guaranteed since prefixSum[i] can't be a negative 
// value. As an example, (5 - 3 % 10) is clearly < (5 % 10). This means we only need to 
// test indices where prefixSum[j] >= prefixSum[i]. 

// 2. In addition, we can immediately stop checking prefixSum[j] after we've found the smallest
// value greater than prefixSum[i]. This is because we're guaranteed everything in prefixSum[] 
// is < M since we used % on the original list, and we want prefixSum[i]-prefixSum[j] to be as
// small of a negative number as possible (since -1%M would be the highest possible obtainable #).
// As an example, say prefixSum was [1,2,5,6,3] and M was 10. If prefixSum[i] = 3, we don't need to 
// check 1 & 2 due to our first rule and we also can stop looking for higher indices after testing 
// 5 since 3-5 % 10 = 8, which is the largest possible sum % 10 we can form. 
// 3-6 % 10 = 7 which is smaller, and so will any other prefixSum[j].

// Thus the question becomes: Given an array prefixSum, find the next largest element to left of
// each index. After finding that element (call it prefixSum[j]), check if we've made a larger value
// by doing prefixSum[i] - prefixSum[j] + M)%M, or in the case that there is no larger element to
// the left, simply check max(currentAnswer, prefixSum[i]).

// We can implement this in O(nlogn) time using a sorted list (set in C++)

int main() {
	int T;
	cin>>T;
	while(T > 0) {
		long long N, M;
		cin>>N>>M;
		long long *prefixSum = new long long[N]; 
		set<long long> leftPrefix;
		long long tmp;
		cin>>tmp;
		tmp %= M;
		leftPrefix.insert(tmp);
		prefixSum[0] = tmp;
		long long answer = tmp;
		for(long long i = 1; i < N; i++) {
			cin>>tmp;
			tmp %= M;
			tmp += prefixSum[i-1];
			tmp %= M;
			prefixSum[i] = tmp;
			it = leftPrefix.upper_bound(tmp);
			if(it == leftPrefix.end()) {
				answer = max(answer, tmp);
			} else {
				answer = max(answer, ((prefixSum[i] - *it + M)%M));
			}
			leftPrefix.insert(tmp);
		}
		cout<<answer<<"\n";
		T--;
	}
    return 0;
}
