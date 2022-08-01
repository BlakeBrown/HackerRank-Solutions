#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin>>T;
    vector<long long> squared;
    long long tmp = 1;
    while(tmp*tmp <= 1000000000) {
    	squared.push_back(tmp*tmp);
    	tmp++;
    }
    while(T > 0) {
    	T--;
    	long long A, B;
    	cin>>A>>B;
    	int count = 0;
    	for(auto it = squared.begin(); it != squared.end(); it++) {
    		if(*it > B) {
    			break;
    		}
    		if(*it >= A) {
    			count++;
    		} 
    	}
    	cout<<count<<"\n";
    }
    return 0;
}
