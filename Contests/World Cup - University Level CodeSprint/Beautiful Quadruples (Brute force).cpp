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
#include <string.h>

using namespace std;

int main(){
    int A;
    int B;
    int C;
    int D;
    cin >> A >> B >> C >> D;
    int ans = 0;
    // LOL... brute force ftw!! :)
    map<string, bool> m;
    string s;
    for(int i = 1; i <= A; i++) {
        for(int j = 1; j <= B; j++) {
            for(int k = 1; k <= C; k++) {
                for(int x = 1; x <= D; x++) {
                    if((i^j^k^x) != 0) {
                        s = to_string(i) + to_string(j) + to_string(k) + to_string(x);
                        sort(s.begin(), s.end());
                        if(m.count(s) == 0) {
                            ans++;
                            m.insert(pair<string, bool>(s, true));
                        }
                    }
                } 
            }  
        }
    }
    cout<<ans<<"\n";
    return 0;
}
