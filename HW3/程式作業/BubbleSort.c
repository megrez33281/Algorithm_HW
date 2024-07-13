#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>


void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;


}

int main(){

	int Case;
	scanf("%d",&Case);
	while(Case--){
       int amounts;
       scanf("%d",&amounts);
       int arrays[amounts];
       for(int i=0; i<amounts; i++){
        scanf("%d",&arrays[i]);
       }
       int swapTime = 0;
       for(int j=amounts-1; j>0; j--){
            for(int i=1; i<=j; i++){
                if(arrays[i] < arrays[i-1]){
                    swap(&arrays[i],&arrays[i-1]);
                    swapTime++;
                }

            }

       }
       printf("Optimal swapping takes %d swaps.\n",swapTime);


	}

}
