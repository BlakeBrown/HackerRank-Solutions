#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


int main() {
    long long n, k;
    cin>>n>>k;
    long long *modArr = new long long[k];
    memset(modArr, 0, sizeof(modArr));
    for(long long i = 0; i < n; i++) {
        long long tmp; 
        cin>>tmp;
        modArr[tmp%k]++;
    }
    long long result = 0;
    // Can include one multiple of the actual number
    if(modArr[0] >= 1) {
        result++;
    }
    for(long long i = 1; i <= k/2; i++) {
       long long tmp = modArr[i];
       if(modArr[k-i] > tmp) {
           tmp = modArr[k-i];
       }
       if(k%2 == 0 && i == k/2 && modArr[k/2] > 0) {
           result++;
       } else {
           result += tmp;  
       }
        
    }
    cout<<result;
    return 0;
}
