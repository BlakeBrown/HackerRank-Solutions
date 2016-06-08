#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <limits.h>
using namespace std;

// Iterator
map<int,int>::iterator it, it2;

int main() {
    int n, tmp;
    cin>>n;
    int *input = new int[n];
    map<int,int> answer; // map is key->number of times key forms a smallest diff pair
    for(int i = 0; i < n; i++) {
       cin>>input[i];
       answer.insert(pair<int,int>(input[i], 0));
    }

    sort(input, input+n);

    // Find the smallest difference
    int smallestDifference = INT_MAX;
    for(int i = 0; i < n-1; i++) {
    	if(input[i+1]-input[i] < smallestDifference) {
    		smallestDifference = input[i+1]-input[i];
    	}
    }
    
    // Iterate over the map and find smallest diff pairs
    for(it = answer.begin(); it != answer.end(); it++) {
    	int key = it->first;
    	it2 = answer.find(key+smallestDifference);
    	if(it2 != answer.end()) {
    		// Found SD pair, increment both indices
    		it->second++;
    		it2->second++;
    	}
    }

    // Print solution
    for(it = answer.begin(); it != answer.end(); it++) {
		for(int i = 0; i < it->second; i++) {
			cout<<it->first<<" ";
		}
	}
    return 0;
}