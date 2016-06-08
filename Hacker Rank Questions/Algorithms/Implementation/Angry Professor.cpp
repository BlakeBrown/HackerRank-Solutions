#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++) {
        int n;
        int k;
        cin >> n >> k;
        vector<int> a(n);
        int numAttending = 0;
        for(int a_i = 0;a_i < n;a_i++) {
            cin >> a[a_i];
            if(a[a_i] <= 0) {
                numAttending++;
            }
        }
        if(numAttending >= k) {
            cout<<"NO\n";
        } else {
            cout<<"YES\n";
        }
    }
    return 0;
}
