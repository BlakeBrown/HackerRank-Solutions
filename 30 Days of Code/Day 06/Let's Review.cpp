include<bits/stdc++.h> 
using  namespace std;
int main(){
    int a,b;
    cin>>a;
    while(a--)
    {
        string s;
        cin>>s;
        int c= s.size();
        string o="",e="";
        for(int i=0;i<c;i++)
        {
            if(i & 1) o+=s[i];
            else e+=s[i];
        }
        cout<<e<<" "<<o<<endl;
    }
}
