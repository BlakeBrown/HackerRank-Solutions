#include<stdio.h>
#include<string.h>
void printEvenIndexChar(char arr[]){
        int len = strlen(arr);
        for (int i = 0;i < len; i++){
            if(i%2 ==0)
                printf("%c", arr[i]);
        }

}

void printOddIndexChar(char arr[]){
       int len = strlen(arr);
       for (int i = 0;i < len; i++){
           if(i%2 !=0)
                printf("%c", arr[i]);
       }

    }

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char s[10000];
    int t;
    scanf("%d",&t);
    for (int a0 = 0; a0 < t; a0++){
        scanf("%s", s);
        printEvenIndexChar(s);
        printf(" ");
        printOddIndexChar(s);
        printf("\n");
    }
    return 0;
}
