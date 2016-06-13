#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<int,int>::iterator it;

// Construct a map of flavor cost -> respective index
// To check if we can make M dollars, iterate over the N flavors and see if M-costOfFlavor[i] exists in map
// This takes O(N) time for the iteration and O(1) time for the lookup
// Overall runtime: O(N)

int main() {
	int T;
	cin>>T;
	while(T > 0) {
		int M, N;
		cin>>M>>N;
		map<int, int> m; // Cost of flavor -> index of flavor
		int *c = new int[N];
		for(int i = 0; i < N; i++) {
			cin>>c[i];
			// Check if c[i] already exists in map
			if(m.count(c[i]) == 0) {
				m.insert(pair<int, int>(c[i], i));
			} else if(c[i] == M/2) {
				// If it already exists in the map and its value is half of M, update
				// it's index to the higher one (this handles duplicates)
				m[c[i]] = i;
			}
		}
		for(int i = 0; i < N; i++) {
			it = m.find(M-c[i]);
			if(it != m.end()) {
				int index = it->second;
				int index2 = i;
				if(index == index2) {
					continue; // Continue to avoid cases where there's only one value of M/2 in the list
				}
				if(index > index2) {
					cout<<index2+1<<" "<<index+1<<"\n";
				} else {
					cout<<index+1<<" "<<index2+1<<"\n";
				}
				break;
			}
		}
		T--;
	}
    return 0;
}
