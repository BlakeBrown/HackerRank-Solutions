#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string,int>::iterator it;

// Put every word from the magazine in a hash table, check if every word from the ransom is in the hash table
bool ransom_note(vector<string> magazine, vector<string> ransom) {
	unordered_map<string, int> map;
    for(int i = 0; i < magazine.size(); i++) {
    	it = map.find(magazine[i]);
    	if(it == map.end()) {
    		map.insert(pair<string, int>(magazine[i], 1));
    	} else {
    		map[magazine[i]]++;
    	}
    }
    for(int i = 0; i < ransom.size(); i++) {
    	it = map.find(ransom[i]);
    	if(it == map.end()) {
    		return false;
    	} else if(it->second == 0) {
			return false;
    	}
    	map[ransom[i]]--;
    }
    return true;
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
