#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Note: Look into Euclid's formula of generating primitive pythagorean triples for future questions
int main() {
    int T;
    cin>>T;
    while(T--) {
    	if(T < 0) {
    		break;
    	}
    	int N;
    	cin>>N;
    	int answer = -1;
    	// Since c > a, a can't be higher than N/2 since that would imply a + c > N 
    	// Normally we would use 3 forloops here, but we can remove the one loop with the realization c = N-a-b
    	// We can remove another loop by subsituting the above equation into a^2 + b^2 = c^2 and rearranging for a 
    	for(int a = 1; a < N/2; a++) {
    		int b = (N*N/2-N*a)/(N-a);
    		int c = N-a-b;
    		if(a*a + b*b == c*c) {
    			if(a*b*c > answer) {
    				answer = a*b*c;
    			}
    		}
    	}
		cout<<answer<<"\n";
    }  
    return 0;
}