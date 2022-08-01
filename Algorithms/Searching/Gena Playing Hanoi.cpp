#include<bits/stdc++.h>
using namespace std;

#define forn(i,n) for(i=0;i<n;i++)
#define forin(i,s,n) for(i=s;i<n;i++)
#define revo(i,s) for(i=s;i>=0;i--)
#define rev(i,s,e) for(i=s;i>=e;i--)
#define pb push_back
#define mp make_pair
#define ll long long
#define endl "\n"
#define PI 3.14159265

map<int,bool> visited;


void possible(int hash, vector<int> &next)
{
    int i,j;
    int tops[4] = {-1,-1,-1,-1};
    int temp;
    forn(i,10)
    {
        if(tops[3&(hash>>(i<<1))] == -1 ) 
            tops[3&(hash>>(i<<1))] = i;
    }
    forn(i,4)
    {
        if(tops[i]!=-1)
        {
            forn(j,4)
            {
                if(tops[j] == -1 || tops[i]<tops[j])
                {
                    temp = hash;
                    temp = temp&(~(3<<(tops[i]<<1)));
                    temp |= (j<<(tops[i]<<1));
                    if(!visited[temp])
                    {
                        visited[temp] = true;
                        next.pb(temp);
                    }
                }
            }
        }
    }
}


ll bfs(int root)
{
    ll ans = 0;
    vector<int> current;
    current.pb(root);
    while(true)
    {
        ans++;
        vector<int> next;
        for(auto x: current)
            possible(x,next);

        if(visited[0])
            return ans;

        current = next;
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //Input Method Defined
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n,i;
    cin>>n;
    int hash = 0;
    forn(i,n)
    {  
        int t;
        cin>>t;
        t--;
        if(hash|=t<<(i<<1));
    }
    
    visited[hash] = true;
    cout<< bfs(hash);

}
