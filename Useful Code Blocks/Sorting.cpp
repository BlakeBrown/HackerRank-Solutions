// Note that
#include <algorithm>
// is required to use sort()

// Ex 1. Integer array
int *arr = new int[n];
sort(arr, arr+n);

// Ex 2. Integer array, descending
int *arr = new int[n];
bool comp(int i, int j) { 
	return i > j; 
}
sort(arr, arr+n, comp);

// Ex 3. String
string s = "dcba";
sort(s.begin(), s.end());

// Ex 4. Vector
vector<int> vec;
sort(vec.begin(), vec.end());

// Ex 5. Vector, descending
vector<int> vec;
sort(vec.rbegin(), vec.rend());
