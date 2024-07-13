#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

int divisors(int n){
    if(n <= 1){
        return 1;
    }

    int sum = 0;
    for(int i=floor(pow(n,0.5)); i>=1; i--){
        if(n%i == 0){
            sum++;
            if(n/i != i){
                sum++;
            }
        }

    }
    return sum;
}

int main(){
    int n;
    scanf("%d",&n);
    while(n--){

        int L,U;
        scanf("%d %d",&L,&U);
        int max_divisor = 0;
        int max_value = L;
        for(int i=L; i<=U; i++){
            int IDivisor = divisors(i);
            if(IDivisor > max_divisor){
                max_divisor = IDivisor;
                max_value = i;
            }

        }
        if(max_divisor == 1){
            printf("Between %d and %d, %d has a maximum of %d divisor.\n",L,U,max_value,max_divisor);
        }
        else{
            printf("Between %d and %d, %d has a maximum of %d divisors.\n",L,U,max_value,max_divisor);}
    }
    return 0;
}
