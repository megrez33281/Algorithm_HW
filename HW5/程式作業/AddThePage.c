#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


int main(){

    long long int n;
    scanf("%lld",&n);
    while(n--){
        long long int sum;
        scanf("%lld",&sum);
        long long int i=0;
        while(sum >= i+1){
            i++;
            sum -= i;

        }
        i+=1;
        printf("%lld %lld",i,i-sum);
	if(n >0 ){printf("\n");}


    }



    return 0;
}
