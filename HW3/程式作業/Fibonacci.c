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
       int n;
       scanf("%d",&n);
       int before = 0;
       int current = 1;
       for(int i=1; i<n; i++){
            int temp = before;
            before = current;
            current = current + temp;
       }
        printf("%d\n",current);

	}

}
