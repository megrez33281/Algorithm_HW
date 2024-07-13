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

        if(x1-x2 == 0 && y1-y2 == 0){ //起點等於終點
            printf("0\n");
        }
        else if(x1-x2 == 0 || y1-y2 == 0){//起點與終點位於同一直線
            printf("1\n");
        }
        else if((int)abs(x1-x2)/abs(y1-y2) == 1){//起點與終點位於同一斜線(斜率為一之斜線)
            printf("1\n");
        }
        else{//其他，最多需兩步，x軸方向一步，y軸方向一步
            printf("2\n");
        }



    }




    return 0;
}
