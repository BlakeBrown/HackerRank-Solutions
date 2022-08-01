#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Don't need to check left, up or 2/4 diagonals
int main() {
    int array[20][20];
    for(int i = 0; i < 20; i++) {
    	for(int j = 0; j < 20; j++) {
    		cin>>array[i][j];
    	}
    } 
    long answer = 0;
    for(int i = 0; i < 20; i++) {
    	for(int j = 0; j < 20; j++) {
    		// Check to the right
    		int a, b, c, d;
    		if(j + 3 < 20) {
    			a = array[i][j];
    			b = array[i][j+1];
    			c = array[i][j+2];
    			d = array[i][j+3];
    			if(a*b*c*d > answer) {
    				answer = a*b*c*d;
    			}
    		}
    		// Check downwards
    		if(i + 3 < 20) {
    			a = array[i][j];
    			b = array[i+1][j];
    			c = array[i+2][j];
    			d = array[i+3][j];
    			if(a*b*c*d > answer) {
    				answer = a*b*c*d;
    			}
    		}
    		// Check diagonally down/right
    		if(j + 3 < 20 && i + 3 < 20) {
    			a = array[i][j];
    			b = array[i+1][j+1];
    			c = array[i+2][j+2];
    			d = array[i+3][j+3];
    			if(a*b*c*d > answer) {
    				answer = a*b*c*d;
    			}
    		}
    		// Check diagonally up/right
    		if(j + 3 < 20 && i - 3 >= 0) {
    			a = array[i][j];
    			b = array[i-1][j+1];
    			c = array[i-2][j+2];
    			d = array[i-3][j+3];
    			if(a*b*c*d > answer) {
    				answer = a*b*c*d;
    			}
    		}
    	}
    } 
    cout<<answer<<"\n";
    return 0;
}