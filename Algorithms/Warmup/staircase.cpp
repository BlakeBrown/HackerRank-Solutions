#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n,i ,j; 
    scanf("%d",&n);
    for(i = 1; i <= n; i++){
        for(j = 1; j<=n-i; j++)
            printf(" ");
        for(j=1; j<=i; j++)
            printf("#");
        printf("\n");
    }
    return 0;
}
