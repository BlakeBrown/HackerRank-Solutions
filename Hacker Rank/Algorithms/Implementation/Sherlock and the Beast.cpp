#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++) {
        int n;
        cin >> n;
        int numThrees = 0;
        while(n%3 != 0) {
        	n -= 5;
        	numThrees++;
        }
        if(n < 0) {
        	cout<<"-1\n";
        } else {
        	while(n != 0) {
        		cout<<"555";
        		n -= 3;
        	}
        	for(int i = 0; i < numThrees; i++) {
        		cout<<"33333";
        	}
        	cout<<"\n";
        }

    }
    return 0;
}
