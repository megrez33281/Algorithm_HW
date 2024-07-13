#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


int main(){

	int Case;
	scanf("%d",&Case);
	for(int i=1; i<=Case; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        int sum=0;
        for(int j=a; j<=b; j++){
            if(j%2 == 1){
                sum += j;
            }

        }
        printf("Case %d: %d\n",i,sum);




	}
	return 0;
}
