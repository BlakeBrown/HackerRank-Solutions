#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
void partition(int size, int arr[]) {
    int left[size],right[size],pivot,equal[size],j=0,k=0,l=0,i;
    pivot = arr[0];
    for(i = 0; i < size; i++) { 
        if(arr[i] < pivot)
            left[j++] = arr[i];
        else if(arr[i] > pivot)
            right[k++] = arr[i];
        else 
            equal[l++] = arr[i];
    }
    for(i = 0; i < j; i++) { 
        printf("%d ", left[i]); 
    }
    for(i = 0; i < l; i++) { 
        printf("%d ", equal[i]); 
    }
    for(i = 0; i < k; i++) { 
        printf("%d ", right[i]); 
    }
    printf("\n");
}
int main(void) {
   int size;
    scanf("%d", &size);
    int arr[size],i;
    for(i = 0; i < size; i++) { 
        scanf("%d", &arr[i]); 
    }
    partition(size, arr);
   
   return 0;
}
