#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// A variation on nim where you move one stone from a pile of higher index to lower index each turn
// See "Nim (MIT notes)" in this folder for an AMAZING explanation on the game theory 
// of nim, including this question
int main() {
    int T;
    cin>>T;
    while(T > 0) {
        int N;
        cin>>N;
        long long *pile = new long long[N]; // pile[i] = # of stones at pile i
        for(int i = 0; i < N; i++) {
            cin>>pile[i];
        }
        // Check for edge case
        if(N == 1) {
            cout<<"Second\n";
            T--;
            continue;
        }
        long long nimSum = 0;
        for(int i = 1; i < N; i++) {
            // A stone at index i is a nim heap of i stones
            if(pile[i] % 2 == 1) {
                nimSum ^= i;
            }
        }
        if(nimSum != 0) {
            cout<<"First\n";
        } else {
            cout<<"Second\n";
        }
        T--;
    }
    return 0;
}
