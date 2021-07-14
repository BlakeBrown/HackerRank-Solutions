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

}

int main()
{
    string s;
    getline(cin, s);
    encryption(s);
    return 0;
}

