#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool is_balanced(string expression) {
    vector<char> s; // Use a stack to keep track of opening brackets
    for(int i = 0; i < expression.size(); i++) {
        if(expression[i] == '{' || expression[i] == '[' || expression[i] == '(') {
            s.push_back(expression[i]);
        } else {
            // Pop the top of the stack and make sure the brackets match
            if(s.size() == 0) {
                return false;
            }
            char c = s.back();
            s.pop_back();
            if(c == '{' && expression[i] != '}') {
                return false;
            }
            if(c == '(' && expression[i] != ')') {
                return false;
            }
            if(c == '[' && expression[i] != ']') {
                return false;
            }
        }
    }
    if(s.size() == 0) {
        return true;
    } else {
        return false;
    }
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
