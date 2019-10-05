#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        int arr[n][n];
        int sum[n]={0},row[n]={0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>arr[i][j];
                sum[j]+=arr[i][j];
                row[i]+=arr[i][j];
            }
        }
        sort(row,row+n);
        sort(sum,sum+n);
        bool check =true;
        for(int i=0;i<n;i++)
        if(row[i]!=sum[i])
        {
            check=false;
            break;
        }
    if(check)
    cout<<"Possible"<<'\n';
    else
    cout<<"Impossible"<<'\n';


    }
return 0;
}

