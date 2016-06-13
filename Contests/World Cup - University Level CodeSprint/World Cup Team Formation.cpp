#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int array[10] ={0};
    for(int i = 0; i < 10; i++) {
        int num;
        cin>>num;
        // Descending insertion sort! :D 
        for(int j = 0; j < 10; j++) {
            if(array[j] < num) {
                for(int k = 9; k >= j; k--) {
                    array[k] = array[k-1];
                }
                array[j] = num;
                break;
            }
        }
    }
    int max = array[0] + array[2] + array[4];
    cout<<max;
    return 0;
}