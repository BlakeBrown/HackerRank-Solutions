#include <bits/stdc++.h>
using namespace std;

// Algorithm: Maintain a list of pairs (t[i] + d[i], i+1), sort by the first value and output by second
// Runtime: O(nlogn) since we have to sort the list
int main() {
	int n;
	cin>>n;
	vector<pair<int, int>> order;
	for(int i = 0; i < n; i++) {
		int t, d;
		cin>>t>>d;
		order.push_back({t+d, i+1});
	}
	sort(order.begin(), order.end());
	for(int i = 0; i < n; i++) {
		cout<<order[i].second<<" ";
	}
    return 0;
}
