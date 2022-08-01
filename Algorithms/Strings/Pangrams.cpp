#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string s;
    getline(cin, s);
    char c = 'a';
    for(int i = 0; i < 26; i++) {
        bool found = false;
        for(int j = 0; j < s.length(); j++) {
            if(tolower(s[j]) == c) {
                found = true;
                break;
            }
        }
        if(!found) {
            cout<<"not pangram";
            break;
        } else if(found && i==25) {
            cout<<"pangram";
        }
        c++;
    }
    return 0;
}