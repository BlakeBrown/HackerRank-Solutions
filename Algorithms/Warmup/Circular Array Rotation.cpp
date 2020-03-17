#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    vector<int>a(n);
    vector<int>b(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    int count=0;
    x=x%n;
     while(y--)
     {
    int z;
    cin>>z;
    z=n+z-x;
    if(z>=n)
    z=z%n;
    cout<<a[z]<<endl;
    }
}
    
    
    
