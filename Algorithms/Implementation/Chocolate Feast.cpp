#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int c;
        int m;
        cin >> n >> c >> m;
        int currentChocolates = n/c;
        long long numChocolates = currentChocolates;
        while(currentChocolates >= m) {
        	// Get as many extra chocolates as he can
        	int extraChocolates = currentChocolates/m;
        	numChocolates += extraChocolates;
        	currentChocolates %= m;
        	currentChocolates += extraChocolates;
        }
        cout<<numChocolates<<"\n";
    }
    return 0;
}
