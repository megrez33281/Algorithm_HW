#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define max(a,b) (a>b)?a:b

int main() {

    int x1,y1,x2,y2;
    while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2) != EOF){
        if(x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0){
            break;
        }

        if(x1-x2 == 0 && y1-y2 == 0){ //�_�I������I
            printf("0\n");
        }
        else if(x1-x2 == 0 || y1-y2 == 0){//�_�I�P���I���P�@���u
            printf("1\n");
        }
        else if((int)abs(x1-x2)/abs(y1-y2) == 1){//�_�I�P���I���P�@�׽u(�ײv���@���׽u)
            printf("1\n");
        }
        else{//��L�A�̦h�ݨ�B�Ax�b��V�@�B�Ay�b��V�@�B
            printf("2\n");
        }



    }




    return 0;
}
