#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
using namespace std;

void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

int main() {
	int x, n;
	cin>>x;
	for(int i = 0; i < x; i++) {
		cin>>n;
		string input;
		getline(cin, input); // read the end of line char
		// Edge case, only 1 person went on the execursion
		// if(n == 1) {
		// 	cout<<"ORDER EXISTS\n";
		// 	continue;
		// }
		unordered_map<string, vector<int> > dupes; // dupe["string"] = list of rows where that string appears
		vector<unordered_map<string, int> > rowIndex; // rowIndex[i] = map of token->index for row i
		vector<int, vector<string> > row; 
		for(int j = 0; j < n; j++) {
			getline(cin, input);
			vector<string> tokens = split(input, ',');
			unordered_map<string, int> tokenIndex;
			for(int k = 0; k < tokens.size(); k++) {
				dupes[tokens[k]].push_back(j);
				tokenIndex[tokens[k]] = k;
			}
		}
		for(auto it = dupes.begin(); it != dupes.end(); it++) {
			vector<int> dupeRow = it->second;
			if(dupeRow.size() > 1) {
				// Found a dupe
				for(int j = 0; j < dupeRow.size(); j++) {
					for(int k = j+1; k < dupeRow.size(); k++) {
						// We have a dupe appearing in rows j, k
						// Check if there's another dupe to the left in row j & to the right in row k
						for(int x = row[dupeRow[0]][it->first]; x < dupeRow[0])
					}
				}

			}
		}
	}
    return 0;
}
