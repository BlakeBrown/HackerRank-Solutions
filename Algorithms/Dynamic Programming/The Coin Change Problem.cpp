#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

// Good explanation of the solution: http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/

int main() {
	// Read input
    int N, M;
    cin>>N;
    cin>>M;
    int *coin = new int[M];
    long *change = new long[N+1];
    for(int i = 0; i < M; i++) {
    	cin>>coin[i];
    }

    // Initialize change (change[i] = numbers of way to make i change) to zero
    memset(change, 0, sizeof(change));

    // Base case: There is 1 way to make change for zero cents, use no coins
    change[0] = 1;

    // Description of algorithm:
    // Iterate over the coins, for each coin the number of ways we can make j
    // change (letting j go from coin->N) is equal to the number of ways we could 
    // make j change before + the number of ways we could make j-coin[i] before.
    // Ex. Consider we have a 2 cent coin and we want to know how we
    // ways we can make change for 6 cents. Iterating from 2 to 6, we simply
    // see that we can make 2 as many ways as we could before + the number
    // of ways we could make 0 before, since now we can just take 0 and add 
    // our 2 cent coin to make 2 cents. For 3 cents, we now have the number
    // of ways we could make 3 before + the number of ways we can make 1 now.
    // Repeat up to 6 and we'll find out how ways we can now make 6.
    // IMPORTANT: This isn't the same as the number of ways we could make
    // 6 cents before + the number of ways we could make 4 cents before. 
    // This is because using the 2 cent coin, we also now have new ways to make 4 
    // cents. Thus we have to START FROM 2 CENTS AND ITERATE UP TO 6 CENTS to figure 
    // out all the new ways to make 6 cents.
    for(int i = 0; i < M; i++) {
        for(int j = coin[i]; j <= N; j++) {
            change[j] += change[j-coin[i]];
        }
    }
    
    // Print solution
    cout<<change[N];
    return 0;
}
