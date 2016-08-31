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

// This question basically boils down to a good understanding of geometry. I could
// explain it pretty well with a diagram, but I'm a little lazy so I'll only draw
// it up if anyone else is curious in the solution. Create an issue on github if
// you'd like to see it! 
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    // Each side needs to be smaller than the sum of all the other sides
    int sum = 0;
    int longestStick = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        if(a[i] > longestStick) {
            longestStick = a[i];
        }
    }
    if(n == 1) {
        // Case 1: Single stick that we have to cut twice to make a triangle
        cout<<"2";
    } else if(n == 2 && a[0] == a[1]) {
        // Case 2: Two sticks of equal length such that we still can't form
        // a triangle after cutting one stick
        cout<<"2";
    } else if(longestStick >= sum-longestStick) {
        // Case 3: The longest stick we have is longer than the sum of all the other 
        // sticks, so we have to cut it to make a valid polygon
        cout<<"1";
    } else {
        // Case 4: We already have a valid polygon
        cout<<"0";
    }
    return 0;
}
