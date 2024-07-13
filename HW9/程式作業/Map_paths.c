#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

//DP問題或是取C
int main(){

    int group;
    scanf("%d",&group);
    while(group--){
        int row,col;
        scanf("%d %d",&row,&col);
        int** arrays = (int**)calloc(row,sizeof(int*));
        for(int i=0; i<row; i++){
            arrays[i] = (int*)calloc(col,sizeof(int));
            arrays[i][0] = 1;
        }
        for(int i=0; i<col; i++){
            arrays[0][i] = 1;
        }
        for(int i=1; i<row; i++){
            for(int j=1; j<col; j++){
                arrays[i][j] = arrays[i][j-1] + arrays[i-1][j];
            }
        }

        printf("%d\n",arrays[row-1][col-1]);
        free(arrays);
    }
    return 0;
}
