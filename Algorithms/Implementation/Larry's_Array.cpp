/*
 * 1) A rotation does not change the parity of the number of inversions.
 * 2) If the array is sortable, then the initial number of inversions is even.
 * 3) If the initial number of inversions is even, then the array is sortable.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int j=0;j<n;j++)
            cin>>v[j];
        int swaps=0;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v.size()-1;j++){
                if(v[j]>v[j+1]){
                    swap(v[j],v[j+1]);
                    swaps++;
                }
            }
        }
        if(swaps%2==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO\n";

    }
    return 0;
}
