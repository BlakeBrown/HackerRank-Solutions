#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin>>T;
    while(T--) {
    	if(T < 0) {
    		break;
    	}
    	int N;
    	cin>>N;
    	int array[N][N];
    	for(int i = 0; i < N; i++) {
    		for(int j = 0; j <= i; j++) {
    			cin>>array[i][j];
    		}
    	}
    	// Using dynamic programming, we can break the triangle down into smaller subtriangles
    	// Consider:
    	//    3
    	//   7 4
    	//  2 4 6
    	// 8 5 9 3
    	// Starting from the second last row, we can form 3 triangles of the smallest size
    	//  2     4     6
    	// 8 5   5 9   9 3   --> take larger of the two numbers
    	// Solve each subtriangle first and work our way up by adding the result to the number above
    	// So new triangle would be:
    	//    3
    	//   7  4
    	// 10 18 18
    	for(int i = N-1; i > 0; i--) {
    		for(int j = 0; j < i; j++) {
    			if(array[i][j] > array[i][j+1]) {
    				array[i-1][j] += array[i][j];
    			} else {
    				array[i-1][j] += array[i][j+1];
    			}
    		}
    	}
    	cout<<array[0][0]<<"\n";
    }   
    return 0;
}