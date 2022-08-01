#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

// Algorithm basically boils down to cleverly applying modulo. We know that no 2 elements can be
// divisible by k, which also means the mod(k) of no two numbers can sum to k. For example with 
// k = 10, we can't have two numbers where first_number%k = 1 and second_number%k = 9, since those 
// would sum to a multiple k. Thus we'll either take all of the numbers whose value mod k is 1, or 
// all of the numbers whose value mod k is 9, whichever is bigger. Don't forget that we can also
// include one multiple of k itself (since we only require that the SUM of any two numbers isn't 
// divisible by k).

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
