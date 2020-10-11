#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int a,k=1;
        cin>>a;
        for(int j=1;j<=a;j++)
        {
            if(j%2!=0)
            {
              k*=2;
            }
            if(j%2==0)
            {
                k++;
            }
        }
        cout<<k<<"\n";
    }
    return 0;
}
