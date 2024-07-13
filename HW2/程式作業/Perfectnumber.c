#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(){

    int Case;
    scanf("%d",&Case);
    while(Case--){
        int a;
        scanf("%d",&a);
        int sum=0;
        int i=floor(sqrt(a));
        for(; i>=1; i--){
            if(a%i==0){
                sum += i;
                //printf("factor:%d\n",i);
                if(i!= 1 && a/i != i){
                sum += a/i;
                //printf("factor:%d\n",a/i);
            }
            }
        }
        if(sum == a){
            printf("%d ",a);
        }

    }
	return 0;
}
