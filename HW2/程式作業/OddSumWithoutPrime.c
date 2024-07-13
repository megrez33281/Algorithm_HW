#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int IsPrime(int n){

    if(n <= 1){return 0;}
    for(int i=floor(sqrt(n)); i>=2; i--){
        if(n%i==0){

            return 0;
        }



    }
    return 1;


}

int main(){

    int Case;
    scanf("%d",&Case);
    while(Case--){
        int a,b;
        scanf("%d %d",&a,&b);
        int sum = 0;
        for(int i=a; i<=b; i++){
            //printf("i=%d,judge:%d\n",i,IsPrime(i));
            if(i%2 == 1 && !IsPrime(i)){
                sum += i;
            }
        }
        printf("%d\n",sum);
    }
	return 0;
}
