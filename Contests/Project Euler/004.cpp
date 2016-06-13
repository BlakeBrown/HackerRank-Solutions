#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<long, bool>::reverse_iterator it;

// Note: Could have used std::vector instead of std::map here!
int main() {

    // Generate all of the palindromes less than 999*999
    map<long, bool> palindromes;
    for(int i = 101; i <= 999; i++) {
        for(int j = 101; j <= 999; j++) {
            // To check if number is a palindrome, first convert i*j to a string
            string test = to_string(i*j);
            // Then check if string is a palindrome by comparing the first half to the second half reversed
            if(equal(test.begin(), test.begin() + test.size()/2, test.rbegin()) ) {
                palindromes.insert(pair<long, bool>(i*j, true));
            }
        }
    }

    int T;
    cin>>T;
    while(T--) {
        if(T < 0) {
            break;
        }
        long N;
        cin>>N;
        // Iterate backwards until we find the first palindrome less than N
        for(it = palindromes.rbegin(); it != palindromes.rend(); it++) {
            if(it->first < N) {
                cout<<it->first<<"\n";
                break;
           }
        }
    }
    return 0;
}