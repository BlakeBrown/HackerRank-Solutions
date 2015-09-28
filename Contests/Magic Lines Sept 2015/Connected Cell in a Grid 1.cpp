#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

const int MAX_N = 10 + 2 ;
int arr[MAX_N][MAX_N] ;
int n, m ;

int testCase ;

int dfs(int x, int y){
    if (x < 0 || x >= m || y < 0 || y >= n || arr[x][y] == 0)
        return 0 ;

    arr[x][y] = 0 ;
    int ret = 1 ;
    for(int i = -1 ; i <= 1 ; i++)
        for(int j = -1 ; j <= 1 ; j++)
            ret += dfs(x+i, y+j);
    return ret ;
}

int main() {
    // cin >> testCase ;
    testCase = 1 ;
    while(testCase--){
        memset(arr, 0, sizeof(arr[0][0]) * MAX_N * MAX_N);

        cin >> m >> n ;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ;j++){
                cin >> arr[i][j];
            }
        }


        int best = 0 ;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ;j++){
                best = max(best, dfs(i, j)) ;
            }
        }

        cout << best << endl ;
    }
    return 0;
}