#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// Algorithm: Sort the toys by price, buy the cheapest toy each time until you run out of money
int main() 
{
    long long n, k; cin >> n >> k;
    vector<int> prices;
    for(int i = 0; i < n; i++)
    {
        int p; cin >> p;
        prices.push_back(p);
    }
    
    sort(prices.begin(), prices.end());
    int count = 0;
    while(k - prices[count] >= 0 && count < n) {
        k -= prices[count];
        count++;
    }
    cout << count << endl;
    
    return 0;
}
