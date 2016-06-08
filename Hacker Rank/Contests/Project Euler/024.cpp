#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Store all factorials from 0-13 to save computation time 
// Note: Algorithm only works up to a string who's length is the same as the array (or replace array with a factorial function to go higher)
long long factorial[14] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800};

// Returns the Nth lexographic permutation of a lexographically sorted string with unique characters
// Uses combinatorics and dynamic programming, see algorithm description below:
// ==== Steps to Algorithm ==== 
// 1. Find the first factorial greater than N, that tells you how many letters you need to get the Nth permutation
// 2. Set aside whatever letters you don't need and compute  N = qb + r, where q is an integer, b is the largest factorial less than N and r is the remainder
// 3. Find the qth index in the unsolved string (remaining letters) and add it to the solved string
// 4. Set N = q and repeat until we compute a remainder of 1 or 0
// ============================
// ========= Example ==========
// Ex. abcdef, find the 11th permutation
// 4! is the first factorial greater than 11, so we only need four letters to get the 11th permutation
// Start a solved string (ab) and a remaining string with the last 4 letters (cdef)
// 11 = 1*3! + 5 -> take the 1st index of (cdef) and place in the solved string, problem becomes "find the 5th permutation of cef"
// Why?^ With (def) we have 3! = 6 permutations, with (cef) we have another 6 permutations -> so this is where the 11th permutation must lie, with (dcf) we have another 6 permutations and so on
// 5 = 2*2! + 1 -> take the 2nd index of (cef) and place in the solved string, problems become "find the 1st permutation of ce"
// Since the remainder is 1 we can break, the first permutation of (ce) is just (ce) and we can add this to the unsolved string
// Therefore the 11th permutation of abcdef is abdfce, done! :) 
// ============================
string lexographicPermutation(string s, long long N) {
    // abcdef, 4
    if(N == 1) {
        return s;
    }
    long long q, index;
    long long b, r;
    string solvedString = "", remainingString = s;
    while(true) {
        q = 1;
        index = 1;
        // Find b
        while(factorial[index+1] < N) {
            index++;
        }
        b = factorial[index];
        // Add however many letters we don't need to the solved string, remove that many from remainingString
        int numSolvedLetters = remainingString.size()-index;
        if(b != N) {
            numSolvedLetters -= 1;
        }
        for(int i = 0; i < numSolvedLetters; i++) {
            solvedString += remainingString[i];
        }
        for(int i = 0; i < numSolvedLetters; i++) {
            remainingString.erase(remainingString.begin());
        }
        // Compute N = qb + r and set N = r
        while((q+1)*b < N) {
            q++;
        }
        N -= q*b;
        // Remove the qth letter from the remaining string and put it in the solved string
        solvedString += remainingString[q];
        remainingString = remainingString.substr(0, q) + remainingString.substr(q+1, remainingString.size()-q-1);
        // If we reach a remainder of 0 or 1, we're done 
        if(N == 0 || N == 1) {
            solvedString += remainingString;
            break;
        }
    }
    return solvedString;
}

int main() {
    string s = "abcdefghijklm";
    int T;
    cin>>T;
    while(T--) {
        if(T < 0) {
            break;
        }
        long long N;
        cin>>N;
        cout<<lexographicPermutation(s, N)<<"\n";
    }
    return 0;
}