#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

set<int>::iterator it, it2;

// Finds # of operations to make n
int findNumOps(int n) {
	int result = 0;
	result += n/5;
	n %= 5;
	result += n/2;
	n %= 2;
	result += n;
	return result;
}

// 2 2 3 3

int main() {
	int T, N;
	cin>>T;
	while(T > 0) {
		cin>>N;
		// Read input into a set since duplicates don't matter
		// We also want the elements to be sorted
		int input;
		set<int> set;
		for(int i = 0; i < N; i++) {
			cin>>input;
			set.insert(input);
		}
		int answer = 0;
		while(set.size() > 1) {
			it = set.begin();
			int x = *it;
			++it;
			int y = *it;
			int diff = y-x;
			int ops = findNumOps(diff);
			set.erase(x);
			set.erase(y);
			set.insert(y-diff);
			answer += ops;
		}
		cout<<"Answer: "<<answer<<"\n";
		T--;
	}
    return 0;
}
