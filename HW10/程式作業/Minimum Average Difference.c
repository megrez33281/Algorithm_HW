#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define max(a,b) (a>b)?a:b


int main() {

    int Test;
    scanf("%d",&Test);
    while(Test--){
        int n;
        scanf("%d",&n);
        int* nums = (int*)calloc(n,sizeof(int));
        for(int i=0; i<n; i++){
            scanf("%d",nums+i);
        }
        int max_index = 0;
        int min = -1;
        for(int index=0; index<n; index++){
            long long int left_mean = 0; //left:0~index
            long long int right_mean = 0; //right:index~n-1
            for(int i=0; i<=index; i++){
                left_mean += nums[i];
            }
            left_mean = (index==-1)?0:(int)floor(left_mean/(index+1));

            for(int i=index+1; i<n; i++){
                right_mean += nums[i];
            }
            right_mean = (index+1>=n)?0:(int)floor(right_mean/(n-index-1));
            int dis = abs(left_mean-right_mean);
            if(min == -1 || dis < min){
                min = dis;
                max_index = index;
            }

        }
        printf("%d\n",max_index);



        free(nums);
    }



    return 0;
}
