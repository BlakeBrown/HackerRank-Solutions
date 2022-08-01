#include <bits/stdc++.h>
using namespace std;

// Helper method for quicksort
// Partition an array so that all elements less than a pivot appear before the elements that are greater than the pivot
// Returns the position of where the pivot gets placed
int partition(vector<int> &arr, int l, int h) {
  // arr = array to be sorted, l = low, h = high, p = pivot, s = swap_position
  int p = arr[h];
  int s = l;
  for(int i = l; i < h; i++) {
    if(arr[i] <= p) {
      // Swap arr[s] with arr[i]
      int tmp = arr[s];
      arr[s++] = arr[i];
      arr[i] = tmp;
    }
  }
  // Swap arr[s] with arr[h]
  int tmp = arr[s];
  arr[s] = arr[h];
  arr[h] = tmp;
  return s;
}

// Performs an in-place quicksort using a Lomuto partition scheme
void quickSort(vector <int> &arr, int l, int h) {
  // arr = array to be sorted, l = low, h = high
  if(l < h) {
    int p = partition(arr, l, h);
    // Question wants to print out the array after every partition
    for(int i = 0; i < arr.size(); i++) {
      cout<<arr[i]<<" ";
    }
    cout<<"\n";
    quickSort(arr, l, p-1);
    quickSort(arr, p+1, h);
  }
}

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n-1);

    return 0;
}
