#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define max(a,b) (a>b)?a:b

void QuickSort(int* arrays, int start, int end){
    //small to big
    if(start >= end){
        return ;
    }
    int pivot = arrays[start];
    int left = start;
    int right = end;
    while(left < right){

        while(left < right && arrays[right] > pivot){
            right--;
        }
        while(left < right && arrays[left] <= pivot){
            left++;
        }




        if(left == right){//exchange
            arrays[start] = arrays[right];
            arrays[right] = pivot;
        }

    }

    QuickSort(arrays,start,right-1);
    QuickSort(arrays,right+1,end);


}


int main() {

    int k;
    scanf("%d",&k);
    while(k--){
        int T,N;
        scanf("%d %d",&T,&N);
        int* values = (int*)calloc(sizeof(int),N);
        for(int i=0; i<N; i++){
            scanf("%d",&values[i]);
        }
        QuickSort(values,0,N-1);
        int* choose = (int*)calloc(sizeof(int),N);
        int sum = 0;
        int total = 0;
        int start = N-1;
        while(start >= 0 && sum != T){//肈impossible瞷┮Τ基㎝T薄猵珿程眖程秨﹍患癹璝礚猭才獽┕膥尿
            sum = 0;
            total = 0;
            for(int i=0; i<N; i++){
                choose[i] = 0;
            }
            for(int i=start; i>=0; i--){
                if(sum + values[i] <= T){
                    sum += values[i];
                    choose[i] = 1;
                    total++;
                }
                if(sum == T){
                    break;
                }
            }
            start--;
        }
        if(sum == T){
            for(int i=N-1; i>=0; i--){
                if(choose[i] == 1){
                    printf("%d",values[i]);
                    total--;
                    if(total != 0){
                        printf(" ");
                    }
                }
            }
            printf("\n");
        }
        else{
            printf("impossible\n");
        }

        free(values);
        free(choose);
    }



    return 0;
}
