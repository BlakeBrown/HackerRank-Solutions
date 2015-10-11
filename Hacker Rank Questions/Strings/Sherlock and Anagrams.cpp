#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

map<string, int>::iterator it;

int main() {
    int T;
    cin>>T;
    while(T--) {
        if(T < 0) {
            break;
        }
        string s;
        cin>>s;
        map<string, int> string_map;
        // Look at all substrings of s
        for(int i = 0; i < s.length(); i++) {
            for(int j = 1; j <= s.length()-i; j++) {
                // Sort the substring (lexographically increasing)
                char letter = 'a';
                string substring, sorted_substring;
                substring = s.substr(i, j);
                for(int k = 0; k < 27; k++) {
                    for(int l = 0; l < substring.length(); l++) {
                        if(substring[l] == letter) {
                            sorted_substring += letter;
                        }
                    }
                    letter++;
                }
                // Count the number of occurences of the (sorted) substring
                if(string_map.count(sorted_substring) == 0) {
                    string_map[sorted_substring] = 0;
                } else {
                    string_map[sorted_substring] += 1;
                }
            }
        }
        int count = 0;
        // For every substring that appears more than once, the number of "unordered anagramic pairs"
        // is equal to n(n+1)/2, where n is the number of occurences 
        for (it = string_map.begin(); it != string_map.end(); it++)
        {
            int value = it->second;
            if(value > 0) {
                count += (value*(value+1)/2);
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}