#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    x=x%n;
     while(y--)
     {
    int z;
    cin>>z;
    z-=x;
    if(z<0)
    z+=n;
    cout<<a[z]<<endl;
    }
}
    
    
    
