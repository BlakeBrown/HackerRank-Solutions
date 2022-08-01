#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Given two strings a and b, finds the longest string that can be constructed such that it is a child of both
// A string x is said to be a child of string y if x can be formed by deleting zero or more characters from y
int c[5005][5005];

string a,b;
int m,n;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin>>a;
    cin>>b;
    //cout<<a<<b<<endl;
    m=a.length();
    n=b.length();
    for(int i=0;i<=m;i++) c[i][0]=0;
    for(int i=0;i<=n;i++) c[0][i]=0;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1] == b[j-1]) c[i][j]=c[i-1][j-1]+1;
            else c[i][j]= max(c[i][j-1],c[i-1][j]);
            //cout<<c[i][j]<<" ";
        }
        //cout<<endl;
    }
    cout<<c[m][n]<<endl;
    
    return 0;
}
