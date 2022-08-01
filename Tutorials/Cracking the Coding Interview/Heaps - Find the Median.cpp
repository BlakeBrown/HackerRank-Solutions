#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    
    // Make two heaps: 
    // 1. biggerHeap - a min heap containing everything bigger than the current median
    // 2. smallerHeap - a max heap containing everything less than the current median
    // Our current median then is then either the average of the top element in both heaps
    // (if there's an even # of elements), or the top of just one of the heaps
    // Overall runtime: O(nlogn) since heap insertion takes logn time, and we calculate the median n times    
    vector<double> biggerHeap;
    vector<double> smallerHeap;
    
    // Base case: Look at the first two elements and put them into their respective heaps
    double val1 = (double) a[0];
    double val2 = (double) a[1];
    double median = (val1+val2)/2;
    if(val1 > median) {
        biggerHeap.push_back(val1);
        smallerHeap.push_back(val2);
    } else {
        biggerHeap.push_back(val2);
        smallerHeap.push_back(val1);
    }
    cout<<fixed<<setprecision(1)<<val1<<"\n";
    cout<<fixed<<setprecision(1)<<median<<"\n";
    
    // For every other element, calculate the median on the fly
    for(int i = 2; i < n; i++) {
        // Push to heaps
        if(a[i] > median) {
            if(biggerHeap.size() == smallerHeap.size() + 1) {
                // Balance
                smallerHeap.push_back(biggerHeap.front());
                push_heap(smallerHeap.begin(), smallerHeap.end());
                pop_heap(biggerHeap.begin(), biggerHeap.end(), greater<int>());
                biggerHeap.pop_back();
                biggerHeap.push_back(a[i]);
                push_heap(biggerHeap.begin(), biggerHeap.end(), greater<int>());
            } else {
                biggerHeap.push_back(a[i]);
                push_heap(biggerHeap.begin(), biggerHeap.end(), greater<int>());
            }
        } else {
            if(smallerHeap.size() == biggerHeap.size() + 1) {
                // Balance
                biggerHeap.push_back(smallerHeap.front());
                push_heap(biggerHeap.begin(), biggerHeap.end(), greater<int>());
                pop_heap(smallerHeap.begin(), smallerHeap.end());
                smallerHeap.pop_back();
                smallerHeap.push_back(a[i]);
                push_heap(smallerHeap.begin(), smallerHeap.end());
            } else {
                smallerHeap.push_back(a[i]);
                push_heap(smallerHeap.begin(), smallerHeap.end());
            }
        }
        // Calc median
        if(biggerHeap.size() == smallerHeap.size()) {
            median = (biggerHeap.front()+smallerHeap.front())/2;
        } else if(biggerHeap.size() > smallerHeap.size()) {
            median = biggerHeap.front();
        } else {
            median = smallerHeap.front();
        }
        cout<<fixed<<setprecision(1)<<median<<"\n";
    }
    return 0;
}
