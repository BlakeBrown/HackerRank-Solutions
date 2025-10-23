#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> vec;

int main()
{
    int n, q, v;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> v;
        vec.push_back(v);
    }
    std::sort(vec.begin(), vec.end());
    vec.resize(std::distance(vec.begin(), std::unique(vec.begin(), vec.end())));
    std::cin >> q;
    while (q--)
    {
        std::cin >> v;
        std::cout << std::distance(std::upper_bound(vec.begin(), vec.end(), v), vec.end())+1 << '\n';
    }
}
