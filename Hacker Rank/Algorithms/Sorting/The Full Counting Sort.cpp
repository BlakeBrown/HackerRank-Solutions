#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

// Stable counting sort
// Total runtime: O(n + k), where is n is the number of elements to sort and k is the size of the largest key
int main() {
    int count[100], n, tmp;
    cin>>n;
    int *key = new int[n]; // Holds the keys for each string
    memset(count, 0, sizeof(count)); // Count will tell us the starting index for each key
    string s, *input = new string[n], *output = new string[n];
    
    // Read input, while calculating key frequencies
    for(int i = 0; i < n; i++) {
        cin>>tmp;
        count[tmp]++; // Count the number of times each key appears
        cin>>s;
        // Store string in an array, following the rules of the problem (the "twist")
        if(i < n/2) {
            input[i] = '-';
        } else {
            input[i]= s;
        }
        key[i] = tmp; // Store the key in an array
    }

    // Calculate the starting index for each key (we did this in the previous challenge)
    int total = 0;
    for(int i = 0; i < 100; i++) {
        total += count[i];
        count[i] = total;
    }

    // Copy to output array, preserving order of inputs with equal keys
    for(int i = n-1; i >= 0; i--) {
        output[count[key[i]]-1] = input[i];
        count[key[i]]--;
    }

    // Print out final array
    for(int i = 0; i < n; i++) {
        cout<<output[i]<<" ";
    }
    return 0;
}