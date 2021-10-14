#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **args) {
    int n, k, r_q, c_q;
    std::cin >> n >> k;
    std::cin >> r_q >> c_q;
    vector<vector<int>> obstacles(k);
    for (int i=0; i <k; i++) {
        int r, c;
        std::cin >> r >> c;
        obstacles[i].push_back(r);
        obstacles[i].push_back(c);
    }
    int r = n-c_q;
    int l = c_q-1;
    int u = n-r_q;
    int d = r_q-1;
    int ur = std::min(u, r);
    int ul = std::min(u, l);
    int ld = std::min(l, d);
    int rd = std::min(r, d);
    for (int i=0; i < k; i++) {
        if (obstacles[i][0] == r_q) {
            if (obstacles[i][1] > c_q) r = std::min(r, obstacles[i][1]-c_q-1);
            else l = std::min(l, c_q-obstacles[i][1]-1);
        } else if (obstacles[i][1] == c_q) {
            if (obstacles[i][0] > r_q) u = std::min(u, obstacles[i][0]-r_q-1);
            else d = std::min(d, r_q-obstacles[i][0]-1);
        } else if (std::abs(obstacles[i][0] -r_q) ==  std::abs(obstacles[i][1] - c_q)) {
            if (obstacles[i][1]>c_q) {
                if (obstacles[i][0]>r_q) ur = std::min(ur, obstacles[i][1]-c_q-1);
                else rd = std::min(rd, obstacles[i][1] - c_q -1);
            } else {
                if (obstacles[i][0]>r_q) ul = std::min(ul, c_q-obstacles[i][1]-1);
                else ld = std::min(ld, c_q-obstacles[i][1]-1);
            }
        }
    }
    std::cout << r+l+u+d+ur+ul+ld+rd;
    return 0;
}
