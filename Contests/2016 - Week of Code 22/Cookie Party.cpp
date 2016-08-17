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


// Just consider a few test cases...

// n < m
// n = 3, m = 10
// 10 % 3 = 1 guest with an extra cookie
// 3 - 1 = 2 guests who also need another cookie, so our answer is 2

// n = m
// n = 10, m = 10
// 10 % 10 = 0 guests with extra cookies
// no guests with extra cookies, so our answer is 0

// n > m
// n = 15, m = 10
// 10 % 15 = 10 guests with a cookie
// 15 - 10 = 5 guests who need a cookie, so our answer is 5

// n = a multiple of m
// n = 20, m = 10
// 10 % 20 = 10 guests with a cookie
// 20 - 10 = 10 guests who need a cookie, so our answer is 10

// m = a multiple of n
// n = 10, m = 20
// 20 % 10 = 0 guests with an extra cookie, so our answer is 0

// We can conclude that our answer is n-(m%n) unless m%n == 0, in which case our answer is 0

int main() {
    int n;
    int m;
    cin >> n >> m;
    int extraCookies = m%n;
	if(extraCookies == 0) {
    	cout<<"0";
    } else {
    	cout<<n-extraCookies;
    }
    return 0;
}
