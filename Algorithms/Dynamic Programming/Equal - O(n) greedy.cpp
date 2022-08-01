#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

// Finds # of operations to take away n chocolates from one person
int numOps(int n) {
	int result = 0;
	result += n/5;
	n %= 5;
	result += n/2;
	n %= 2;
	result += n;
	return result;
}

// If Christy chooses one co-worker and gives everyone else candy,
// this is equivalent to reducing the amount of candy for just that
// one co-worker and leaving everyone else's chocolates untouched.

// Using this fact, we can calculate in O(1) time how many 
// operations it takes to remove n chocolates - see numOps()

// The optimal solution is usually to reduce everyone's # of chocolates
// down to the minimum # in the group, however it may also be the case that
// {min-1, min-2, min-3, min-4} are more optimal since we have the option of
// taking away up to 5 chocolates at a time.

// Using all this information, we can use a greedy approach where
// we iterate over every co-worker and reduce their chocolates down
// to the minimum.

// Runtime: O(N)

int main() {
	int T, N;
	cin>>T;
	while(T > 0) {
		cin>>N;
		int input, smallestNum = INT_MAX;
		// Read input, find the smallest #
		vector<int> vec;
		for(int i = 0; i < N; i++) {
			cin>>input;
			vec.push_back(input);
			if(input < smallestNum) {
				smallestNum = input;
			}
		}
		// Iterate over the list and try reducing everyone's candies
		// down to {min, min-1, min-2, min-3, min-4}. Take the minimum 
		// answer.
		int answer = INT_MAX;
		for(int i = 0; i < 4; i++) {
			int tmpAnswer = 0;
			for(int j = 0; j < N; j++) {
				int minOps = INT_MAX;
				tmpAnswer += numOps(vec[j]-smallestNum+i);
			}
			if(tmpAnswer < answer) {
				answer = tmpAnswer;
			}
		}
		cout<<answer<<"\n";
		T--;
	}
    return 0;
}