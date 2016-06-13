#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int N;
	cin>>N;
	for(int i = 0; i < N; i++) {
		double one, two, three;
		cin>>one>>two>>three;
		double conversion = (1/one)*(1/two)*(1/three);
		if(conversion <= 1) {
			cout<<"0\n";
		} else {
			cout<<(int) (conversion*100000-100000)<<"\n";
		}
	}
    return 0;
}
