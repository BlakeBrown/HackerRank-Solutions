#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Key to this question is that the even fibonacci numbers can be expressed as their own sequence with
// their own linear reccurence relation, which makes calculating their sum much faster
int main() {
    int T;
    cin>>T;
    while(T--) {
        if(T < 0) {
            break;
        }
        vector<long long> fib_array;
        long long N, sum = 10, index = 2;
        cin>>N;
        fib_array.push_back(2);
        fib_array.push_back(8);
        while(true) {
            fib_array.push_back(4*fib_array[index-1] + fib_array[index-2]);
            if(fib_array[index] > N) {
                break;
            } else {
                sum+=fib_array[index];
            }
            index++;
        }
        cout<<sum<<"\n";
    }
    return 0;
}