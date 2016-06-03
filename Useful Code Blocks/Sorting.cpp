// Ex 1. Integer array
#include <algorithm>
int *input = new int[n];
sort(input, input+n);

// Note: to sort descending we define the following

// Helper method for std::sort, sorts descending
bool comp(int i, int j) { 
	return i > j; 
}

// and make use of the 3rd parameter
sort(input, input+n, comp);

// Ex 2. String
#include <algorithm>
string s = "dcba";
sort(s.begin(), s.end());