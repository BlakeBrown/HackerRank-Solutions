#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Both series have closed form solutions
int main() {
    int T;
    cin>>T;
    while(T--) {
    	if(T < 0) {
    		break;
    	}
    	double N;
    	cin>>N;
    	long long sum_of_squares = (long long) round(N*(N+1)*(N+0.5)/3);
    	long long sum = N*(N+1)/2;
    	long long square_of_sums = sum*sum;
    	cout<<sum_of_squares-square_of_sums<<"\n";
    }
    return 0;
}