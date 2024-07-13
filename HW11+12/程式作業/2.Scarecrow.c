#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define max(a,b) (a>b)?a:b


int main() {

    int Cases;
    scanf("%d",&Cases);
    for(int sample=1; sample<=Cases; sample++){
        int n;
        scanf("%d ",&n);
        char* field = (char*)calloc(n,sizeof(char));
        scanf("%s", field);
        printf("Case %d: ",sample);
        getchar();
        int scarecrow = 0;
        for(int i=0; i<n; i++){
            if(field[i] == '.'){ //�ϥγg���t��k�ѨM�A�q���M����k�̦n�����p�O��N�_��H��b�k���A�䦸�O��e��m
                if(i+1 < n){
                    field[i+1] = '#';
                    field[i] = '#';
                    if(i+2 < n){
                        field[i+2] = '#';
                    }
                    scarecrow++;
                }
                else{
                    field[i] = '#';

                    if(i > 0){
                        field[i-1] = '#';
                    }
                    if(i+1 < n){
                        field[i+1] = '#';
                    }
                    scarecrow++;
                }
            }
        }
        printf("%d\n",scarecrow);



        free(field);
    }
    return 0;
}
