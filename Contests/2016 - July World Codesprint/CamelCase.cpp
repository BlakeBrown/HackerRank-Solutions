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

// Add the number of uppercase letters in s, add one
int main(){
    string s;
    cin >> s;
    int count = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= 65 && s[i] <= 90) {
        	count++;
        } 
    }
    cout<<count+1;
    return 0;
}
