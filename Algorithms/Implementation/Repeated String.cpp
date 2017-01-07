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


int main(){
    string s;
    cin >> s;
    long long n;
    cin >> n;
    // Count the number of a's in the original string
    long long numA = 0;
    for(int i = 0; i < s.size(); i++) {
    	if(s[i] == 'a') {
    		numA++;
    	}
    }
    // Count the number of times the original string repeats and add that to our answer
    long long answer = (n/s.size())*numA;
    // Count any remaining A's
    for(int i = 0; i < n%s.size(); i++) {
    	if(s[i] == 'a') {
    		answer++;
    	}
    }
    cout<<answer;
    return 0;
}
