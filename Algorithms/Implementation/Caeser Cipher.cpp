#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// This question is easy once you understand how chars are stored in a computers memory.
// http://www.asciitable.com/ -> every char is actually mapped to a decimal (integer) value, this
// means that the integer value of 65 represents 'A', 97 represents 'a', etc. 
// C++ is great because it will implicity convert char <-> integer

// Note: There is one tricky part however, which is that a char can not an integer value greater than 
// 127. This is because a standard char is only 1 byte/8 bits (with one sign bit), so the largest value 
// it can hold is 2^7 - 1 = 127. Thus when we perform our rotations, we should temporarily store
// the char in a larger data type such as an integer so that we can go higher than 127, then convert
// it back to an integer after doing the arithmetic.

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    k %= 26; // Since 26 rotations = same letter
    for(int i = 0; i < s.size(); i++) {
    	if(s[i] >= 'A' && s[i] <= 'Z') {
    		// Uppercase
    		int letter = s[i];
    		letter += k;
    		if(letter > 'Z') {
    			letter %= 'Z';
    			letter += 'A';
    			letter--;
    		}
    		s[i] = letter;
    	}
    	if(s[i] >= 'a' && s[i] <= 'z') {
    		// Lowercase
    		int letter = s[i];
    		letter += k;
    		if(letter > 'z') {
    			letter %= 'z';
    			letter += 'a';
    			letter--;
    		}
    		s[i] = letter;
    	}
    }
    cout<<s<<"\n";
    return 0;
}
