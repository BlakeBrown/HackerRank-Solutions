#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    double N;
    cin>>N;
    
    double num_zeroes = 0;
    double num_positive = 0;
    double num_negative = 0;

    for(int i = 0; i < N; i++) {
        int x;
        cin>>x;
        if(x < 0) {
            num_negative++;
        } else if(x == 0) {
            num_zeroes++;
        } else {
            num_positive++;
        }
    }
    // Truncates to a maximum of 3 decimal places
    // 10/5 = 0.5 (not 0.500)
    // 3/10 = 0.333
    cout<<round(((num_positive/N)*1000.0))/1000.0<<"\n";
    cout<<round(((num_negative/N)*1000.0))/1000.0<<"\n";
    cout<<round(((num_zeroes/N)*1000.0))/1000.0<<"\n";
    return 0;
}