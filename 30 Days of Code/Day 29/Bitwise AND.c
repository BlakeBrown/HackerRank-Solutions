#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int t;
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        scanf("%d %d",&n,&k);
        int max = 0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if ((i & j) < k && (i & j) > max){
                    max = i&j;
                }
            }
        }
        printf("%d\n", max);
    }
    return 0;
}
