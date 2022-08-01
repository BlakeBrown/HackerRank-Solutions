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

// We can represent the position of kangaroo 1 & 2 using two linear equations
// Kangaroo 1: x1 + v1*t, Kangaroo 2: x2 + v2*t
// There'll be an intersection if t = (x2-x1)/(v1-v2) is an integer value, we just need
// to first check that v1 >= v2 so that we have a positive integer in the denominator.
int main(){
    int x1;
    int v1;
    int x2;
    int v2;
    cin >> x1 >> v1 >> x2 >> v2;
    if(v2 >= v1) {
        cout<<"NO";
    } else if((x2-x1)%(v1-v2) == 0) {
        cout<<"YES";
    } else {
        cout<<"NO";
    }
    return 0;
}
