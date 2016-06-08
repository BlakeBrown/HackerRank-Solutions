#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Another dp problem! :)
int main() {
    int T;
    cin>>T;
    // Note: We require either a 32x32 board, or decreasing loops after we've solved half the board
    bool chess[32][32]; // true = player 1 wins, false = player 2 wins
    // Base cases
    chess[0][0] = false;
    chess[0][1] = false;
    chess[0][2] = true;
    chess[1][0] = false;
    chess[1][1] = false;
    chess[2][0] = true;
    // Iterate across the diagonals of the board, each possible move will have a known solution
    for(int i = 3; i < 32; i++) {
        int tmp = i;
        for(int j = 0; j <= i; j++) {
            // Player 1 wins if he can move the piece to any place where the starting player loses
            if(tmp - 2 >= 0 && j + 1 < 15 && chess[tmp-2][j+1] == false) {
                chess[tmp][j] = true;
            } else if(tmp - 2 >= 0 && j - 1 >= 0 && chess[tmp-2][j-1] == false) {
                chess[tmp][j] = true;
            } else if(tmp + 1 < 15 && j - 2 >= 0 && chess[tmp+1][j-2] == false) {
                chess[tmp][j] = true;
            } else if(tmp - 1 >= 0 && j - 2 >= 0 && chess[tmp-1][j-2] == false) {
                chess[tmp][j] = true;
            } else {
                chess[tmp][j] = false;
            }
            tmp--;
        }
    }
    while(T > 0) {
        int x, y;
        cin>>x>>y;
        if(chess[x-1][y-1]) {
            cout<<"First\n";
        } else {
            cout<<"Second\n";
        }
        T--;
    } 
    return 0;
}
