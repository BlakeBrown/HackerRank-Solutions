#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Trick: Super large numbers should be read/stored as a string
// (Other than that we can brute force the solution)
int main() {
    int T;
    cin>>T;
    while(T--) {
        if(T < 0) {
            break;
        }
        int N, k;
        cin>>N;
        cin>>k;
        // Read number in as a string and iterate over the characters
        // Much less memory intensive
        string s;
        cin>>s;
        vector<int> subArray;
        long long answer = 0; 
        for(int i = 0; i < N; i++) {
            // Covert from ascii char to int
            int x = (int) s[i]-'0';
            subArray.push_back(x);
            if(i >= k) {
                long long test = subArray[0];
                for(int j = 1; j < k; j++) {
                    test *= subArray[j];
                }
                if(test > answer) {
                    answer = test;
                }
                subArray.erase(subArray.begin());
            }
        }
        cout<<answer<<"\n";
    }
    return 0;
}