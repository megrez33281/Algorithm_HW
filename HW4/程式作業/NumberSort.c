#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>




int main(){

    int Case;
    scanf("%d",&Case);
    while(Case--){
        char arrays[101][51] = {};
        char arraysI[101][51] = {};
        int order[101] = {0};
        int swapTime[101] = {0};
        for(int i=0; i<101; i++){
            order[i] = i;
        }
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0; i<m; i++){
            scanf("%s",&arrays[i]);
            for(int j=0; j<strlen(arrays[i]); j++){
                arraysI[i][j] = arrays[i][j];
            }
        }

        for(int i=0; i<m; i++){
            int sum = 0;
            for(int j=n-1; j>=0; j--){
                for(int k=1; k<=j; k++){
                    if(arrays[i][k] < arrays[i][k-1]){
                        sum++;
                        char temp = arrays[i][k];
                        arrays[i][k] = arrays[i][k-1];
                        arrays[i][k-1] = temp;
                    }
                }
            }
            swapTime[i] = sum;

        }

        for(int i=m-1; i>=0; i--){
            for(int j=1; j<=i; j++){
                if(swapTime[j] < swapTime[j-1]){
                    int temp = swapTime[j];
                    swapTime[j] = swapTime[j-1];
                    swapTime[j-1] = temp;
                    temp = order[j];
                    order[j] = order[j-1];
                    order[j-1] = temp;

                }

            }
        }
        for(int i=0; i<m; i++){
            printf("%s\n",arraysI[order[i]]);

        }

    }


	return 0;
}
