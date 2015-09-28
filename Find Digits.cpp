#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin>>T;
    while(T--) {
        if(T < 0) {
            break;
        }
        long long N;
        cin>>N;
        // Remember array[10] means array is defined from 0-9 (was stuck on this for a while >.<)
        bool array[10] = {false};
        for(int i = 1; i <= 9; i++) {
            if(N%i == 0) {
                array[i] = true;
            } 
        }
        int count = 0;
        // Iterates through all of the digits of a number (starting from last digit and going backwards)!
        do {
            int digit = N % 10;
            if(array[digit]) {
                count += 1;
            }
            N /= 10;
        } while (N > 0);
        cout<<count<<"\n";     
    }
    return 0;
}