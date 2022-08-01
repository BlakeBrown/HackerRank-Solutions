#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int R;
        int C;
        cin >> R >> C;
        vector<string> G(R);
        for(int G_i = 0;G_i < R;G_i++){
           cin >> G[G_i];
        }
        int r;
        int c;
        cin >> r >> c;
        vector<string> P(r);
        for(int P_i = 0;P_i < r;P_i++){
           cin >> P[P_i];
        }
        // Optimization - continue if P > G
        if(r > R || c > C) {
            cout<<"NO\n";
            continue;
        }
        bool patternExists = false;
        // Main algorithm
        for(int i = 0; i < R; i++) {
            bool foundMatch = false;
            for(int j = 0; j < C; j++) {
                if(G[i][j] == P[0][0] && (i+r <= R) && (j+c <= C)) {
                    // Potential match
                    bool match = true;
                    for(int x = 0; x < r; x++) {
                        bool rowMatch = true;
                        for(int y = 0; y < c; y++) {
                            if(P[x][y] != G[x+i][y+j]) {
                                rowMatch = false;
                                match = false;
                                break;
                            }
                        }
                        if(!rowMatch) {
                            break;
                        }
                    }
                    if(match) {
                        foundMatch = true;
                        break;
                    }
                }
            }
            if(foundMatch) {
                patternExists = true;
                break;
            }
        }
        if(patternExists) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }
    return 0;
}
