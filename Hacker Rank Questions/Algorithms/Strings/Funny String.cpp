#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() { 
    int N;
    cin>>N;
    for(int i = 0; i < N; i++) {
    	string s;
    	cin>>s;
    	bool funny = true;
    	// Only need to iterate over half the string
    	for(int j = 0; j < s.length()/2; j++) {
            int k;
            k = s.length()-j-1;
            // We don't need to cast chars to ints, using the "-" operator automatically converts chars to their ascii values
            if(abs((s[k] - s[k-1])) != abs((s[j] - s[j+1]))) {
                cout<<"Not Funny"<<"\n";
                funny = false;
                break;
            }
    	}
        if(funny) {
            cout<<"Funny"<<"\n";
        }
    }
    return 0;
}