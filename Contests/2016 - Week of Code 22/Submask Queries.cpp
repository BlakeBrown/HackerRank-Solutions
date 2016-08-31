#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

// Gets the value of a binary string
long long getValue(string s) {
	long long val = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '1') {
			val += pow(2, i);
		}
	}
	return val;
}

// Observation 1: We don't need to actually generate every subset
// Observation 2: We can quickly represent a subset using the value of it's binary string (ex. 0101 -> 5)
// Observation 3: Storing a list of Q1 and Q2 queries will allow us to use them only when they're needed
int main() {
	int n, m;
	cin>>n>>m;

	// Q[i].first = time that query occured, Q[i].second.first = subset, Q[i].second.second = x
	vector<pair<int, pair<long long, long long> > > Q1;
	vector<pair<int, pair<long long, long long> > > Q2;

	string s = string(n, '1');
	long long subset = getValue(s); // subset = value of binary string s
	long long x = 0; // x = value of query
	pair<long long, long long> subsetPair = pair<long long, long long>(subset, x);
	int t = 0; // t = time that query occured

	// Initializing all subsets to 0 is equivalent to a single Q1 query
	Q1.push_back(pair<int, pair<long long, long long> >(t, subsetPair));
	t++;

	// // Main algorithm
	for(int i = 0; i < m; i++) {
		int q;
		cin>>q;
		if(q == 1) {
			// Query 1: We know every subset of S = x at time t, so just store this info
			cin>>x;
			cin>>s;
			subset = getValue(s);
			subsetPair = pair<long long, long long>(subset, x);
			Q1.push_back(pair<int, pair<long long, long long> >(t, subsetPair));
			t++;
		} else if(q == 2) {
			// Query 2: We need to XOR every subset of S with x at time t, just store this info
			cin>>x;
			cin>>s;
			subset = getValue(s);
			subsetPair = pair<long long, long long>(subset, x);
			Q2.push_back(pair<int, pair<long long, long long> >(t, subsetPair));
			t++;
		} else {
			// Query 3: Search through previous Q1 and Q2 queries to find the value of S
			cin>>s;
			subset = getValue(s);
			int timeOfLastQuery;
			// Find the most recent Q1 query that set the value of the subset
			for(int i = Q1.size()-1; i >= 0; i--) {
				if((Q1[i].second.first & subset) == subset) {
					timeOfLastQuery = Q1[i].first;
					x = Q1[i].second.second;
					break;
				}
			}
			// Find all Q2 queries that also affected the subset
			for(int i = Q2.size()-1; i >= 0; i--) {
				if(Q2[i].first < timeOfLastQuery) {
					break;
				}
				if((Q2[i].second.first & subset) == subset) {
					x ^= Q2[i].second.second;
				}
			}
			cout<<x<<"\n";
		}
	}
    return 0;
}
