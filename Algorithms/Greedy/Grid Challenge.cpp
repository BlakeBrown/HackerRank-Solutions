#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Algorithm: Sort each row lexicographically, then check if each of the columns are lexicographically sorted
// Runtime: O(n^2) -> O(nlogn) to sort every row, but it takes O(n^2) time to check that every column is sorted
int main() {
	int T;
	cin>>T;
	while(T > 0) {
		int N;
		cin>>N;
		string *matrix = new string[N];
		// Read input, sort every row
		for(int i = 0; i < N; i++) {
			cin>>matrix[i];
			sort(matrix[i].begin(), matrix[i].end());
		}
		bool arrangeable = true;
		for(int i = 0; i < N; i++) {
			for(int j = 1; j < N; j++) {
				if(matrix[j][i] < matrix[j-1][i]) {
					arrangeable = false;
				}
			}
			// Small optimization: Break immediately if we've found that a column isn't sorted
			if(!arrangeable) {
				break;
			}
		}
		if(arrangeable) {
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
		T--;
	}
    return 0;
}
