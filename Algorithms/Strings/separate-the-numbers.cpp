#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check(string str,int ind ,long long int prev){
    if(ind == str.size() -1 && prev - (str[ind] -'0') == -1){
        
        return true;
    }
    else if(ind == str.size() ) return true;
    long long int k=0;
    int i;
    for(i =ind; i < str.size(); i++){
        k = k *10 + (str[i]-'0');
        if(prev-k == -1){
             if( i+ 1 == str.size()){
              return true;
            
            }
            return check(str,i+1, k);
        }  
        else if(k - prev > 1) {
            return false;
        }
        
    }
    return false;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >>n;
    while(n--){
        string str;
        int k;
        cin >>str;
        //cout<< str <<" i " << n <<endl;
        if(str[0] == '0' || str.size() <=1){
            cout << "NO"<<endl; 
            continue;
        }
        long long int j=0;
        bool f =false;
        for(k =0; k<str.size()-1; k++){
            j = j*10 +str[k]-'0';
            f = check(str,k+1,j);
            if(f ==true){ 
                //cout << k <<" "<<str <<endl; 
                cout <<"YES"<< " " << j <<endl;
                break;
            }
        }
        if(f== false)             cout <<"NO" <<endl;

    }
    
    
    return 0;
}
