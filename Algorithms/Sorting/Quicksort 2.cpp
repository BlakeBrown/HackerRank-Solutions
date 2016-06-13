#include <bits/stdc++.h>
using namespace std;

// Question requires you to do a non "in-place" quick sort
// Sorting questions on HackerRank aren't the best...
void quickSort(vector <int> &arr) {
  
  if(arr.size() < 2) {
    return; // array is already sorted
  } 

  vector<int> left, right;

  // Partition code from last challenge
  int p = arr[0];
  for(int i = 0; i < arr.size(); i++) {
    if(arr[i] < p) {
        left.push_back(arr[i]);
    } else if(arr[i] > p) {
        right.push_back(arr[i]);
    }
  }

  // Recursively sort
  quickSort(left);
  quickSort(right);

  // Copy left array back into the original array
  for(int i = 0; i < left.size(); i++) {
      arr[i] = left[i];
      cout<<left[i]<< " ";
  }

  // Copy the pivot between left & right arrays
  arr[left.size()] = p;
  cout<<p<< " ";

  // Copy right array back into the original array
  for(int i = 0; i < right.size(); ++i) {
      arr[left.size() + i + 1] = right[i];
      cout<<right[i]<<" ";
  }
  cout<<"\n";
}

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);

    return 0;
}
