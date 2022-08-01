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

// Count the # of different chars in each string
int main(){
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        string s;
        cin >> s;
        bool newChar[26];
        for(int i = 0; i < 26; i++) {
        	newChar[i] = false;
        }
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
        	if(!newChar[s[i]-97]) {
        		newChar[s[i]-97] = true;
        		count++;
        	}
        }
        cout<<count<<"\n";
    }
    return 0;
}
