#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;


int main() {
	int N, M;
	cin>>N>>M;
	long long *list = new long long[N];
	for(int i = 0; i < N; i++) {
		list[i] = 0;
	}
	// Rather than performing each query, store the effect of each query on an index
	for(int i = 0; i < M; i++) {
		int a, b;
		long long k;
		cin>>a>>b>>k;
		list[a-1] += k;
		if(b < N) {
			list[b] -= k;
		}
	}
	long long answer = 0, updated_list_value = 0;
	for(int i = 0; i < N; i++) {
		updated_list_value += list[i];
		if(updated_list_value > answer) {
			answer = updated_list_value;
		}
	}
	cout<<answer<<"\n";
    return 0;
}
