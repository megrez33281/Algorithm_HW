#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define max(a,b) (a>b)?a:b
#define min(a,b) (a>b)?b:a

int main() {

    int times;
    scanf("%d",&times);
    while(times--){
        int row;
        scanf("%d",&row);
        row++;
        row/= 2; //得到對應的列數
        long long int nums = row*row; //得到到該列為止共有多少數字
        long long int last = nums*2-1;//得到該列最後一個數字
        long long int answer = 1;
        for(int i=0; i<3; i++){
            answer*= last;
            last -= 2;
        }
        printf("%lld\n",  answer);
    }


    return 0;
}
