#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int answer[27] = {0};
    string string1, string2;
    cin>>string1;
    cin>>string2;
    for(int i = 0; i < string1.length(); i++) {
        answer[string1[i]-97]++;     
    }
    for(int i = 0; i < string2.length(); i++) {
        answer[string2[i]-97]--;  
    }
    int sum = 0;
    for(int i = 0; i < 27; i++) {
        sum += abs(answer[i]);
    }
    cout<<sum;
    return 0;
}