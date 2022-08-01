#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Greedy approach: Always take the largest number from the back of the array and swap it with the current index
// (it's basically a selection sort where we stop after K swaps)
// Runtime: O(n^2) -> this isn't quite enough to pass all test cases

// Improved approach: Since we know the list only contains numbers 1 -> N, we can
// simply maintain a hashtable of each number and it's index in the array. Every time we swap,
// just lookup the index of the largest element in the hashtable.
// Runtime: O(n)

int main() {
  int N, K;
  cin>>N>>K;
  vector<int> arr;
  arr.resize(N);
  unordered_map<int, int> index_of_elem;
  for(int i = 0; i < N; i++) {
    cin>>arr[i];
    index_of_elem[arr[i]] = i;
  }
  for(int i = 0; i < N; i++) {
    if(K == 0) {
      break;
    }
    if(arr[i] == N-i) {
      continue;
    }
    // Swap i'th largest element to the front
    index_of_elem[arr[i]] = index_of_elem[N-i];
    arr[index_of_elem[N-i]] = arr[i];
    arr[i] = N-i;
    K--;
  }
  for(int i = 0; i < N; i++) {
    cout<<arr[i]<<" ";
  }
  return 0;
}
