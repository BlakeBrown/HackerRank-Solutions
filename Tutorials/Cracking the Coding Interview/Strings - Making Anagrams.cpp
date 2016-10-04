#include <cmath>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Given two strings, finds the minimum number of character deletions required to make the two strings anagrams.
int main() {
    char s1[10010],s2[10010];
    cin>>s1>>s2;
    int a[26]={0};
    for(int i=0;i<strlen(s1);i++)
        a[s1[i]-'a']++;
    for(int i=0;i<strlen(s2);i++)
        a[s2[i]-'a']--;
    long long int ans = 0;
    for(int i=0;i<26;i++)
        ans += abs(a[i]);
    cout<<ans<<endl;
    return 0;
}
