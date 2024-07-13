#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


int main(){

	int Case;
	scanf("%d",&Case);
	while(Case--){
        int n;
        scanf("%d",&n);
        while( n != 1 && n != 4){
            int digitssum = 0;
            while(n > 0){
                digitssum += (n%10)*(n%10);
                n/=10;
            }
            n = digitssum;
        }
        if(n == 1){
            printf("Happy\n");
        }
        else{
            printf("Not Happy");
        }





	}
	return 0;
}
