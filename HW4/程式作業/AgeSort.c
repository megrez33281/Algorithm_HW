#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

void quickSort(int* arrays, int len){
    /*for(int i=0; i<len; i++){

        printf("%d ",arrays[i] );
    }
    printf("\n");*/
    if(len <= 1){return;}

    int pivot = arrays[0];
    int left = 0;
    int right = len-1;
    while(left < right){
        while(left < right && arrays[right] >= pivot){
            right--;
        }
        while(left < right && arrays[left] <= pivot){
            left++;
        }


        if(left < right){
            int temp = arrays[left];
            arrays[left] = arrays[right];
            arrays[right] = temp;

        }

    }
    arrays[0] = arrays[left];
    arrays[left] = pivot;

    quickSort(arrays,left);
    quickSort(arrays+left+1,len-left-1);
}

int main(){

    int n;
    while(scanf("%d",&n) != EOF){

        if(n == 0){break;}
        int* ages = (int*)calloc(n,sizeof(int));
        for(int i=0; i<n; i++){

            scanf("%d",&ages[i]);
        }

        quickSort(ages,n);
        for(int i=0; i<n; i++){
            printf("%d",ages[i]);
            if(i < n-1){
                printf(" ");
            }
        }
        printf("\n");

        free(ages);

    }

	return 0;
}
