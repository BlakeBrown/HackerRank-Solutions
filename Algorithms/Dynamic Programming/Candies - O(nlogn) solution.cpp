#include <bits/stdc++.h>
using namespace std;

// Solution 2: Check candies in order of increasing rating, runs in O(nlogn)
int main() {
    int N;
    int rating[100000];
    int candy[100000];
    vector<pair<int, int>> order;
    cin>>N;
    for(int i = 0; i < N; i++) {
        candy[i] = 1;
    }
    for(int i = 0; i < N; i++) {
        cin>>rating[i];
        order.push_back({rating[i], i});
    }
    sort(order.begin(), order.end());
    for(int i = 0; i < N; i++) {
        int x = order[i].second;
        if(x-1 >= 0 && rating[x-1] < rating[x]) {
            candy[x] = max(candy[x], candy[x-1]+1);
        }
        if(x+1 <= N-1 && rating[x+1] < rating[x]) {
            candy[x] = max(candy[x], candy[x+1]+1);
        }
    }
    long long total = 0;
    for(int i = 0; i < N; i++) {
        total += candy[i];
    }
    cout<<total;
    return 0;
}
