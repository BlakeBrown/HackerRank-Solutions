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
    int n1;
    int n2;
    int n3;
    cin >> n1 >> n2 >> n3;
    int h1 = 0, h2 = 0, h3 = 0; // heights of the 3 stacks
    vector<int> tower1(n1);
    for(int i = 0; i < n1; i++){
       cin>>tower1[i];
       h1 += tower1[i];
    }
    vector<int> tower2(n2);
    for(int i = 0; i < n2; i++){
       cin>>tower2[i];
       h2 += tower2[i];
    }
    vector<int> tower3(n3);
    for(int i = 0; i < n3; i++){
       cin>>tower3[i];
       h3 += tower3[i];
    }
    // Use a greedy approach, always remove cylinders from the tallest tower until all towers
    // have the same height.
    bool equalHeight = false;
    if(h1 == h2 && h2 == h3) {
        equalHeight = true;
    }
    int r1 = 0, r2 = 0, r3 = 0; // Store the indices of which cylinder to remove
    while(!equalHeight) {
        if(h1 >= h2 && h1 >= h3) {
            h1 -= tower1[r1];
            r1++;
        } else if(h2 >= h1 && h2 >= h3) {
            h2 -= tower2[r2];
            r2++;
        } else if(h3 >= h1 && h3 >= h2) {
            h3 -= tower3[r3];
            r3++;
        }
        if((h1 == h2 && h2 == h3) || (h1 == 0 && h2 == 0 && h3 == 0)) {
            equalHeight = true;
        }
    }
    cout<<h1;
    return 0;
}
