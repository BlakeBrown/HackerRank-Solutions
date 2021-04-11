#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {   
        int t;
        scanf("%d",&t);
        for (int i=0; i < t; i++){
            int flag = 0;
            int num;
            scanf("%d", &num);
            if (num < 2){
                printf("Not prime\n");
            }
            else
            {
                for (int j=2; j <= sqrt(num); j++){
                    if (num%j == 0){
                        flag =1;
                        break;
                    }
                }
                if (flag == 0){
                   printf("Prime\n");
                }
                else {
                   printf("Not prime\n");
                }
            }

        }

    return 0;   
}

