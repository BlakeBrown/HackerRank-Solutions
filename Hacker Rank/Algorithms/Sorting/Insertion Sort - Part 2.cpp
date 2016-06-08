#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;

void insertionSort(int ar_size, int *  ar) {
    for(int i = 1; i < ar_size; i++) {
        int V = ar[i];
        for(int j = i; j >= 0; j--) {
            if(V < ar[j-1]) {
                ar[j] = ar[j-1];
            } else {
                ar[j] = V;
                break;
            }
        }
        // Print the array after each iteration
        for(int i = 0; i < ar_size; i++) {
            cout<<ar[i]<<" ";
        }
        cout<<"\n";
    }
}

int main(void) {
   
    int _ar_size;
    cin >> _ar_size;

    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
        cin >> _ar[_ar_i];
    }

   insertionSort(_ar_size, _ar);
   
   return 0;
}
