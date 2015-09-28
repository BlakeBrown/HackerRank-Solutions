#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a;
    long b;
    long long c;
    char d;
    float e;
    double f;
    scanf("%d %ld %lld %c %f %lf", &a, &b, &c, &d, &e, &f);
    printf("%d\n%ld\n%lld\n%c\n%f\n%lf", a, b, c, d, e, f);
    return 0;
}

/* Could also have done (as suggested in comments) 

std::string s;
for(int i=0; i<6; i++) {
    std::cin >> s;
    std::cout << s << std::endl;
}

*/