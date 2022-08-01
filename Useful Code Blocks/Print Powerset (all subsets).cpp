// Example 1: Print all subsets of a string (can be easily modified to print other data)
// Runs in O(n*2^n) time

#include <string>
#include <cmath>
using namespace std;

// Powerset = set of all subsets
void printPowerSet(string s) {
    // Note there are 2^n subsets for a set of size n
    int numSubsets = pow(2, s.size());
    // Run a counter from 000...0 to 111...1
    for(int counter = 0; counter < numSubsets; counter++) {
        for(int j = 0; j < s.size(); j++) {
            // Check if jth bit in the counter is set, if so print the corresponding char
            if(counter & (1<<j)) {
                printf("%c", s[j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    printPowerSet("abcd"); // prints all subsets of abcd
    return 0;
}