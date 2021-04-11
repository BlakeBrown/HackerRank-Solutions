#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    

    int da,ma,ya,de,me,ye;
    scanf("%d%d%d", &da,&ma,&ya);
    scanf("%d%d%d", &de,&me,&ye);

    int fine = 0;
    if(ye==ya){

        if(me < ma){
            fine = (ma - me) * 500;
        }
        else if( (me == ma) && (de < da) ){
            fine = (da - de) * 15;
        }

    }
    else if(ye < ya){
        fine = 10000;
    }
    printf("%d", fine);
    return 0;
}
