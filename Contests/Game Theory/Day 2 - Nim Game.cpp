#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Great explanation of how xor solves nim at: https://en.wikipedia.org/wiki/Nim
int main() {
    int T;
    cin>>T;
    while(T > 0) {
    	int n;
    	int nimSum, tmp;
    	cin>>n>>nimSum;
    	for(int i = 1; i < n; i++) {
    		cin>>tmp;
    		nimSum ^= tmp;
    	}
    	if(nimSum != 0) {
    		cout<<"First\n";
    	} else {
    		cout<<"Second\n";
    	}
    	T--;
    }
    return 0;
}
