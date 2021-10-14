/*
 * complexity: 1/10*O(N^2)
 * author: mohab metwally
*/
#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> bigint;
    bigint.push_back(1);

    for (int i=2; i <=n; i++) {
        //(1) calculate factorial
        for (auto it=bigint.begin(); it!=bigint.end(); it++) {
            *it *=i;
        }
        //(2) move overflowing numbers (>=10) to new integer
        for (int d=0; d<=bigint.size(); d++) {
            //(3) detect over flow
            if (bigint[d]<10) continue;

            if (d==bigint.size()-1) bigint.push_back(0);

            //(4) add overflow to subsequent int
            bigint[d+1] += bigint[d]/10;
            //(5) keep reminder to the current int
            bigint[d]%= 10;
        }
    }
    for (auto it = bigint.rbegin(); it!=bigint.rend(); it++) {
        cout << *it;
    }
    return 0;
}
