#include <bits/stdc++.h>
using namespace std;

// A variation on the common "Candy Distribution Problem", with two variations
// a) There's a larger range of people we need to check
// b) Each person has a minimum # of "candies"

// We can solve this using the O(nlogn) solution to the candy problem. We
// iterate over each person in order of increasing ratings, and increase their
// number of "shares" (candies) as necessary

int main() {
    int N;
    int rating[100000];
    int shares[100000];
    vector<pair<int, int>> order;
    cin>>N;
    for(int i = 0; i < N; i++) {
        cin>>rating[i];
        order.push_back({rating[i], i});
    }
    for(int i = 0; i < N; i++) {
        cin>>shares[i];
    }
    sort(order.begin(), order.end());
    for(int i = 0; i < N; i++) {
        int x = order[i].second;
        for(int j = max(x-10, 0); j <= min(x+10, N-1); j++) {
            if(rating[x] > rating[j]) {
                shares[x] = max(shares[x], shares[j]+1);
            }
        }
    }
    long long total = 0;
    for(int i = 0; i < N; i++) {
        total += shares[i];
    }
    cout<<total;
    return 0;
}
