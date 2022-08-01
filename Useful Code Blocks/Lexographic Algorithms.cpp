// ===================================================================
// ===================================================================
// ======= Algorithm 1: Find the Next Lexographic Permutation ========
// ===================================================================
// ===================================================================

// Summary of Algorithm: 
// Look for a strictly lexographically decreasing substring at the end of the string
// If the decreasing substring is ever broken (ie a lexographically bigger char comes after a lexographically smaller char)
// ex. 2431: 431 is decreasing but then 2 breaks the sequence
// Call the decreasing substring the suffix and the char that breaks the sequence the pivot
// ex.  431 = suffix and 2 = pivot 
// Swap the pivot with the next lexographically larger char in the suffix
// ex. 2431 -> 3421
// Sort the suffix to be lexographically increasing
// ex. 2431 -> 2134
// Done! :) 
// Note: If a pivot is never found, then the string is already the largest possible lexograpical permutation

// Returns the next lexographic permutation of string s
string nextLexographicPermutation(string s) {
    // Find pivot
    char pivot;
    int index_of_pivot;
    for(int i = s.length(); i > 0; i--) {
        if(s[i] > s[i-1]) {
            pivot = s[i-1];
            index_of_pivot = i-1;
            break;
        }
    }
    // Swap pivot with next lexographically larger char in suffix
    string before_pivot, suffix;
    char swap_char; 
    before_pivot = s.substr(0, index_of_pivot);
    suffix = s.substr(index_of_pivot+1, s.length()-index_of_pivot-1);
    for(int i = suffix.length()-1; i >= 0; i--) {
        if(suffix[i] > pivot) {
            swap_char = suffix[i];
            suffix.erase(i, 1);
            suffix+=pivot;
            pivot = swap_char;
            break;
        }
    }
    // Sort the suffix lexographically (nlog(n) time complexity)
    sort(suffix.begin(), suffix.end());
    // Done! :D
    return before_pivot+pivot+suffix;
}

// ===================================================================
// ===================================================================
// ======= Algorithm 2: Find the Nth Lexographic Permutation =========
// ==== Currently requires a sorted string with unique characters ====
// ===================================================================
// ===================================================================

// Summary of Algorithm:
// Uses combinatorics and dynamic programming, see algorithm description below:
// ==== Steps to Algorithm ==== 
// 1. Find the first factorial greater than N, that tells you how many letters you need to get the Nth permutation
// 2. Set aside whatever letters you don't need and compute  N = qb + r, where q is an integer, b is the largest factorial less than N and r is the remainder
// 3. Find the qth index in the unsolved string (remaining letters) and add it to the solved string
// 4. Set N = q and repeat until we compute a remainder of 1 or 0
// ============================
// ========= Example ==========
// Ex. abcdef, find the 12th permutation
// 4! is the first factorial greater than 12, so we only need four letters to get the 12th permutation
// Start a solved string (ab) and a remaining string with the last 4 letters (cdef)
// Compute N = qb + r, q*b must be less than N
// 12 = 1*3! + 6 -> take the 1st index of (cdef) and place in the solved string, problem becomes "find the 6th permutation of cef"
// Why?^ With (cdef) we have 3! = 6 permutations of the last three letters, with (dcef) we have another 6 permutations -> so this is where the 12th permutation must lie, with (ecdf) we have another 6 permutations and so on
// 6 = 2*2! + 2 -> take the 2nd index of (cef) and place in the solved string, problem becomes "find the 2nd permutation of ce"
// 2 = 1*1! + 1 -> take the 1st index of (ce) and place in the solved string, problem becomes "find the 1st permutation of e"
// Since the remainder is 1 we can break, add the remaining unsolved string to the solved string
// Therefore the 12th permutation of abcdef is abdfec, done! :) 
// ============================

// Store all factorials from 0-13 to save computation time 
// Note: Algorithm only works up to a string who's length is the same as the array (replace array with a factorial function to go higher)
long long factorial[14] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800};

// Returns the Nth lexographic permutation of a lexographically sorted string s with unique characters
string lexographicPermutation(string s, long long N) {
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
        int numSolvedLetters = remainingString.size()-index-1;
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