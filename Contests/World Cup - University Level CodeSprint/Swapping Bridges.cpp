#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T; 
    cin>>T;
    for(int i = 0; i < T; i++) {
        int N;
        cin>>N;
        int array[N] = {0};
        for(int j = 0; j < N; j++) {
            int bridge;
            cin>>bridge;
            array[j] = bridge;
        }
        int sum = 0;
        for(int j = 0; j < N; j++) {
            if(array[j] == j) {
                sum+=2;
                cout<<"added 2"<<"\n";
            } else if(j < (N-1) && array[j] == (j+1) && array[j+1] == j) {
                cout<<"added 1"<<"\n";
                sum+=1;
            }
        }
        cout<<"Sum is: "<<sum<<"\n";
    }
    return 0;
}