#include <bits/stdc++.h>
using namespace std;

// Slower version of insertion-sort as shown here: https://en.wikipedia.org/wiki/Insertion_sort
// Returns the number of shifts performed during the sort
int insertionSort(vector<int> arr, int n) {
    int shifts = 0;
    for(int i = 1; i < n; i++) {
        int V = arr[i];
        int j = i;
        while(j > 0 && arr[j-1] > arr[j]) {
            int tmp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = tmp;
            shifts++;
            j--;
        }
    }
    return shifts;
}

// Helper method for quicksort
// Partition an array so that all elements less than a pivot appear before the elements that are greater than the pivot
// Returns the position of where the pivot gets placed
int partition(vector<int> &arr, int l, int h, int &swaps) {
  // arr = array to be sorted, l = low, h = high, p = pivot, s = swap_position
  int p = arr[h];
  int s = l;
  for(int i = l; i < h; i++) {
    if(arr[i] <= p) {
      // Swap arr[s] with arr[i]
      int tmp = arr[s];
      arr[s++] = arr[i];
      arr[i] = tmp;
      swaps++;
    }
  }
  // Swap arr[s] with arr[h]
  int tmp = arr[s];
  arr[s] = arr[h];
  arr[h] = tmp;
  swaps++;
  return s;
}

// Performs an in-place quicksort using a Lomuto partition scheme
void quickSort(vector <int> &arr, int l, int h, int &swaps) {
  // arr = array to be sorted, l = low, h = high
  if(l < h) {
    int p = partition(arr, l, h, swaps);
    quickSort(arr, l, p-1, swaps);
    quickSort(arr, p+1, h, swaps);
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

    int shifts = insertionSort(arr, n);
    int swaps = 0;
    quickSort(arr, 0, n-1, swaps);
    cout<<shifts-swaps<<"\n";

    return 0;
}
