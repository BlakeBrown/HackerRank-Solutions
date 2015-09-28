#include <stdio.h>
#include <cmath>

void update(int *a,int *b) {
    *a = *a + *b; 
    *b = std::abs(*a-*b-*b); 
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

/* Note to self:
myvar = 25;
foo = &myvar; ---> The "&" operator will return the memory address of myvar
 *foo ---> The "*" operator (known as the "dereference" operator) will return the value stored at the memory address

*/