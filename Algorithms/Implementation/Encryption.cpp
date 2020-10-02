#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
void encryption(string s) {
    int l=s.size();
    int row=round(sqrt(l));
    int column;
    if(row>=sqrt(l))
        column=row;
    else column=row+1;
    for(int j=0;j<column;++j)
        {
        for(int i=j; i<l;i+=column)
        {
            cout << s[i];
        }
        cout << ' ';
        }

   /* if(lo*hi>=l)
    {
        int k=0;
        char ar[lo][hi];
        while(k<l)
        {
        for(int i=0;i<lo;i++)
        {
           for(int j=0;j<hi;j++)
           {
               ar[i][j]=s.at(k);
               k++;

           }
        }
     }
     for(int i=0;i<hi;i++)
        {
           for(int j=0;j<hi-1;j++)
           {
             cout<<ar[j][i];
           }
           cout<<" ";
        }
    }
    else if(lo*hi<l)
    {
         int k=0;
        char ar[hi][hi];
        while(k<l)
        {
        for(int i=0;i<hi;i++)
        {
           for(int j=0;j<hi;j++)
           {
               ar[i][j]=s.at(k);
               k++;
           }
        }
     }
     for(int i=0;i<hi;i++)
        {
           for(int j=0;j<hi-1;j++)
           {
             cout<<ar[j][i];
           }
           cout<<" ";
        }
    }
    */

}

int main()
{
    string s;
    getline(cin, s);
    encryption(s);
    return 0;
}

