#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int frequency[100001];
    for(int i = 1; i <= 100000; i++) {
        frequency[i] = 0;
    }
    int n, m;
    cin>>n;
    // Count # of appearances in list 1
    for(int i = 0; i < n; i++) {
        int tmp;
        cin>>tmp;
        frequency[tmp]++;
    }
    cin>>m;
    // Subtract # of appearances in list 2
    for(int i = 0; i < m; i++) {
        int tmp;
        cin>>tmp;
        frequency[tmp]--;
    }
    // Any frequency[i] != 0 does not appear the same # of times in each list
    for(int i = 1; i <= 10000; i++) {
        if(frequency[i] != 0) {
            cout<<i<<" ";
        }
    }
    return 0;
}
