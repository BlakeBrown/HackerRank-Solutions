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

// Currently not a working solution -> need to come back and fix this later
int main(){
    int A;
    int B;
    int C;
    int D;
    cin >> A >> B >> C >> D;
    // Find all the permutations then subtract cases where A^B^C^D = 0
    // We can break this down into 2 cases
    // Case 1: A^B = 0, so C^D = 0
    // Case 2: A^B != 0, so C^D = A^B
    long long result = A*B*C*D;
    // Swap vars so B >= A and D >= C
    if(A > B) {
    	int tmp = B;
    	B = A;
    	A = tmp;
    }
    if(C > D) {
    	int tmp = D;
    	D = C;
    	C = tmp;
    }
    cout<<"Result 1:"<<result<<"\n"; // 24
    // Case 1
    result -= A*C;
    cout<<"Result 2:"<<result<<"\n"; // 21

    // Case 2
    for(int i = 1; i <= A; i++) {
    	for(int j = i+1; j <= B; j++) {
    		// Note: j is always bigger than i
    		if(C >= j && D >= j) {
    			result-=4;
    		} else if(C >= i && C < j && D >= j) {
    			result-=2;
    		} else {
    			break;
    		}
    	}
    	cout<<"Result loop: "<<result<<"\n"; // 15, 11
    }
    cout<<result;
    return 0;
}
