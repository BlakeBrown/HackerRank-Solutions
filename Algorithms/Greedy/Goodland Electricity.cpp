#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int main() {
  int n, k;
  cin>>n>>k;
  vector<int> arr, dist_to_next_tower;
  arr.resize(n);
  dist_to_next_tower.resize(n);
  for(int i = 0; i < n; i++) {
    cin>>arr[i];
  }

  // Use DP to find dist_to_next_tower for each town
  int distance = INT_MAX;
  for(int i = n-1; i >= 0; i--) {
    dist_to_next_tower[i] = distance;
    if(arr[i] == 1) {
      distance = 1;
      continue;
    }
    if(distance == INT_MAX) {
      continue;
    }
    distance++;
  }
  
  int answer = 0;
  int skipped_towns = 0;
  for(int i = 0; i < n; i++) {
    // Case 1: Last tower
    if(dist_to_next_tower[i] == INT_MAX) {
      // If the last tower can't light up the remaining towns, problem's impossible
      if(skipped_towns >= k || n-i > k) {
        cout<<"-1";
        return 0;
      } else {
        answer++;
        break;
      }
    }
    // Case 2: No tower, skip to the next town
    if(arr[i] == 0) {
      skipped_towns++;
      continue;
    }
    // Case 3: Tower, but we can use the next one instead
    if(skipped_towns + dist_to_next_tower[i] < k) {
      skipped_towns++;
      continue;
    }
    // Case 4: We've skipped more towns than we can light up, problem's impossible
    if(skipped_towns >= k) {
      cout<<"-1";
      return 0;
    }
    // Case 5: We need to turn on the current tower
    answer++;
    skipped_towns = 0 - k + 1;
  }
  cout<<answer<<"\n";
  return 0;
}
