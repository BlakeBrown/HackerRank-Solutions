#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin>>T;
    while(T > 0) {
    	int N, M;
    	cin>>N>>M;
    	if(M == 1) {
    		cout<<"2\n"; // Player 1 loses if all towers are height 1 (edge case)
    	} else if(N % 2 == 0) {
    		cout<<"2\n"; // Player 1 loses if there are an even number of towers
    	} else {
    		cout<<"1\n"; // Player 1 wins
    	}
    	T--;
    }   
    return 0;
}
