// Example 1: Print all permutations of a string (can be easily modified to print other data)
// Runs in O(p) time, where p is the number of permutations of the string. Note that this
// is much more efficient than a naive algorihtm for strings with duplicate letters.
// "aaaaa" for example, has only one permutation.

// Algorithm description: We can construct all permutations by continuously taking one char off
// the string and permuting the remaining chars.
// Ex. "abcd", on the first iteration we construct
// 'a' + permute("bcd")
// 'b' + permute("acd")
// 'c' + permute("abd")
// 'd' + permute("abc")
// We note that this avoids creating duplicates since with "aaaa" we would have
// permute("aaaa") = 'a' + permute("aaa")
// permute("aaa") = 'a' + permute("aa")
// permute("a") = 'a' + permute("a")
// permute("a") just returns 'a', so we end up creating 1 string as opposed to 16 (4!)

#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

void permute(string s, unordered_map<char,int> count, string perm) {
	// cout<<"New iteration\n";
	// if(perm.size() == s.size()-1) {
	// 	cout<<"Length 1\n";
	// 	perm += s[0];
	// 	cout<<perm<<"\n";
	// 	return;
	// } else {
		// cout<<"hello world\n";
	// cout<<"new iteration\n";
		unordered_map<char,int>::iterator it;	
		for(it = count.begin(); it != count.end(); it++) {
			// cout<<"testing new char...\n";
			if(it->second > 0) {
				// cout<<count[it->first]<<"\n";
				count[it->first]--;
				// cout<<count[it->first]<<"\n";
				// cout<<perm<<" + "<<it->first<<" = "<<perm + it->first<<"\n";
				if(s.size() - perm.size() == 1) {
					// Permutation is complete
					cout<<perm + it->first<<"\n";
				} else {
					permute(s, count, perm + it->first);
				}
				// cout<<"test\n";
				// cout<<"finished with "<<it->first<<"\n";
				count[it->first]++;
				// cout<<"incremented\n";
			}
		}
		// cout<<perm<<"\n";
	// }
}

// Powerset = set of all subsets
void printPermutations(string s) {
	// Count the number of times each letter appears in the string
	unordered_map<char,int> count; // count['a'] -> # of times 'a' appears in s
	for(int i = 0; i < s.size(); i++) {
		count[s[i]]++;
	}
	permute(s, count, "");
}

int main()
{
    printPermutations("abcdefghijklmnopqrstuvwxyz"); // prints all subsets of abcd
    return 0;
}