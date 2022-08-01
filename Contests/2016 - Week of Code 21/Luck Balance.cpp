#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int N, K, L, T;
	cin>>N>>K;
	int luck = 0;
	vector<int> contest;
	for(int i = 0; i < N; i++) {
		cin>>L;
		cin>>T;
		if(T == 0) {
			// Lose all unimportant contests
			luck += L;
		} else {
			contest.push_back(L);
		}
	}
	// Sort important contests descending
	sort(contest.rbegin(), contest.rend());
	while(K > 0 && contest.size() > 0) {
		// Lose as many (of the largest contests) as possible
		luck += contest[0];
		contest.erase(contest.begin());
		K--;
	}
	for(int i = 0; i < contest.size(); i++) {
		// Win the rest
		luck -= contest[i];
	}
	cout<<luck;
    return 0;
}
