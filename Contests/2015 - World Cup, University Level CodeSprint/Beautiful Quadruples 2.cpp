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
    int *nimSum = new int[3001];
    memset(nimSum, 0, sizeof(nimSum));
    int numPerm = 0;
    for(int i = 1; i <= A; i++) {
    	for(int j = i; j <= B; j++) {
            nimSum[i^j]++;
            numPerm++;
    	}
    }
    int result = 0;
    int copies = 0;
    for(int i = 1; i <= C; i++) {
        for(int j = i; j <= D; j++) {
            result += (numPerm-nimSum[i^j]-copies);
            copies++;
        }
    }
    cout<<result;
    return 0;
}
