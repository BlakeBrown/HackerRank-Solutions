#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long sumUpToN(long n) {
    return n*(n+1)/2;
}

int main() {
    int T;
    cin>>T;
    for(int i = 0; i < T; i++) {
        long num;
        cin>>num;
        num -= 1;
        long num_of_3 = num/3;
        long num_of_5 = num/5;
        long num_of_15 = num/15;
        long sum = 3*sumUpToN(num_of_3) + 5*sumUpToN(num_of_5) - 15*sumUpToN(num_of_15);
        cout<<sum<<"\n";
    }
    return 0;
}