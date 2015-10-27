#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <map>
using namespace std;


int main() {
    int N;
    cin>>N;
    list<string> stringList;
    map<string, int> stringMap;
    string s;
    for(int i = 0; i < N; i++) {
    	cin>>s;
    	stringList.push_back(s);
    }
    stringList.sort();
    int count = 1;
    for(auto it = stringList.begin(); it != stringList.end(); ++it) {
       stringMap.insert(pair<string,int>(*it,count)); 
       count++;
    }
    int Q;
    cin>>Q;
    long nameSum;
    for(int i = 0; i < Q; i++) {
        nameSum = 0;
    	cin>>s;
    	for(int j = 0; j < s.length(); j++) {
    		nameSum += (int)s[j]-64;
    	}
    	cout<<nameSum*stringMap[s]<<"\n";
    }
    return 0;
}