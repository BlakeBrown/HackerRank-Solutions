#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **args) {
    int H, W;
    cin >> H >> W;
    int A[H+2][W+2];
    //pad the matrix with zero reference height
    for (int i=0; i <= H+1; i++) {
        for (int j=0; j<= W+1; j++) {
            if (i==0 || j==0 || i>H || j>W) A[i][j] = 0;
            else cin >> A[i][j];

        }
    }
    int area=2*H*W; //upper and lower area, 100>=H,W>=1
    for (int i=1; i<=H; i++) {
        for (int j=1; j <=W; j++) {
            //sum the area along the height forward, and backward
            area += std::max(0, A[i][j]-A[i][j-1]);
            area += std::max(0, A[i][j]-A[i][j+1]);
            //sum the area along the width forward, and backward
            area += std::max(0, A[i][j]-A[i-1][j]);
            area += std::max(0, A[i][j]-A[i+1][j]);
        }
    }
    std::cout << area;
    return 0;
}
