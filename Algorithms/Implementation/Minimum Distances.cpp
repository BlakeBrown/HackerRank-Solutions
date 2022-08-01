#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Brute force approach passes all test cases, but as with most questions of this format
// we can do better using a hashtable to get O(n) instead of O(n^2)
int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n;i++){
       cin >> A[i];
    }
    int minDistance = INT_MAX;
    for(int i = 0; i < n; i++) {
    	for(int j = i+1; j < n; j++) {
    		if(A[i] == A[j] && j-i < minDistance) {
    			minDistance = j-i;
    		}
    	}
    }
    if(minDistance == INT_MAX) {
    	cout<<"-1";
    } else {
    	cout<<minDistance;
    }
    return 0;
}
