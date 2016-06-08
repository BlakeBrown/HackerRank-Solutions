#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int lonelyinteger(vector < int > a) {
    int result = 0;
    // Succesive xor's will cancel each other out
    // i.e 6 ^ 6 ^ 8 ^ 8 ^ 9 = 9
    // IMPORTANT TO REMEBER: The order in which the xor's are applied doesn't matter (xor operators are "commutative" )
    // Also note: 0 ^ x  = x

    for(int i = 0; i < a.size(); i++) {
        result ^= a[i];
    }
    return result;
}

int main() {
    int res;
    
    int _a_size;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    
    res = lonelyinteger(_a);
    cout << res;
    
    return 0;
}
