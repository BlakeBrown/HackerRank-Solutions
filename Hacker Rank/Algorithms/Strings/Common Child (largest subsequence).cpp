#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Question asks us to find the largest common subsequence between two strings (note: different than largest substring!)
// Great explanation of a DP (dynamic programming) algorithm: https://www.youtube.com/watch?v=NnD96abizww
int main() {
    string s1, s2;
    cin>>s1;
    cin>>s2;
    // We need to use a staticly allocated array or we will run out of stack space (results in a segmentation fault)
    static int array[5000][5000];
    // Initialize array
    for(int i = 0; i < s1.length(); i++) {
       for(int j = 0; j < s2.length(); j++) {
           array[i][j] = 0;
       }
    }
    // Use dynamic programming to determine the size of the largest subsequence
    // We can break the problem down into parts by considering each string, character by character
    // If the two strings have the same char at the same index, then the largest subsequence at that point
    // is simply the largest subsequence before that char was added to either string + 1
    // If the two strings DON'T have the same char at the same index, then the largest subsequence at that point
    // is the larger of either a) string1 without that char or b) string2 without that char 
    for(int i = 0; i < s1.length(); i++) {
        for(int j = 0; j < s2.length(); j++) {
            if(s1[i] == s2[j]) {
                // Check if a diagonal cell (a smaller subsequence) exists 
                // If it does, increment by 1 + the value of the cell (size of the previous subsequence)
                // Otherwise set the cell equal to 1 
                if(i > 0 && j > 0) {
                    array[i][j] = array[i-1][j-1] + 1;
                } else {
                    array[i][j] = 1;
                }
            } else if(i == 0 && j > 0) {
                // Take the cell above
                array[i][j] = array[i][j-1];
            } else if(i > 0 && j == 0) {
                // Take the cell to the left
                array[i][j] = array[i-1][j];
            } else if(i > 0 && j > 0) {
                // Take the bigger of the cell above or to the left
                if(array[i][j-1] > array[i-1][j]) {
                    array[i][j] = array[i][j-1];
                } else {
                    array[i][j] = array[i-1][j];
                }
            }
        }
    }
    cout<<array[s1.length()-1][s2.length()-1];
    return 0;
}