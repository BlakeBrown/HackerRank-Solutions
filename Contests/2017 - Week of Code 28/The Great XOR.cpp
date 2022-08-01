#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int visit(int ***A, int i, int j, int n, int m, int size) {
    (*A)[i][j] = -1;
    size++;
    if(i-1 >= 0 && j-1 >= 0 && (*A)[i-1][j-1] == 1) {
        size += visit(A, i-1, j-1, n, m, 0);
    }
    if(i-1 >= 0 && (*A)[i-1][j] == 1) {
        size += visit(A, i-1, j, n, m, 0);
    }
    if(i-1 >= 0 && j+1 < m && (*A)[i-1][j+1] == 1) {
        size += visit(A, i-1, j+1, n, m, 0);
    }
    if(j-1 >= 0 && (*A)[i][j-1] == 1) {
        size += visit(A, i, j-1, n, m, 0);
    }
    if(j+1 < m && (*A)[i][j+1] == 1) {
        size += visit(A, i, j+1, n, m, 0);
    }
    if(i+1 < n && j-1 >= 0 && (*A)[i+1][j-1] == 1) {
        size += visit(A, i+1, j-1, n, m, 0);
    }
    if(i+1 < n && (*A)[i+1][j] == 1) {
        size += visit(A, i+1, j, n, m, 0);
    }
    if(i+1 < n && j+1 < m && (*A)[i+1][j+1] == 1) {
        size += visit(A, i+1, j+1, n, m, 0);
    }
    return size;
}


int main(){
    long long q;
    cin >> q;
    for(long long a0 = 0; a0 < q; a0++){
        long long x;
        cin>>x;
        // Find the length of the binary representation of x
        long long length = 1;
        long long powerOf2 = 1;
        while(powerOf2 < x) {
        	powerOf2 *= 2;
        	length++;
        }
        // Iterate over x's binary representation, each time we hit a 1
        // we can immediately deduct from the total of satisfying #'s
        powerOf2 = 1;
        long long numSatisfying = x-1;
        for(long long i = 0; i < length; i++) {
        	if(x & powerOf2) {
        		numSatisfying -= min(powerOf2, x-powerOf2);
        	}
            powerOf2*=2;
        }
        cout<<numSatisfying<<"\n";
    }
    return 0;
}

