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
        int numbers;
        int odd = 0;
        int even = 0;
        for(int i=0; i<4; i++){
            scanf("%d",&numbers);
            odd += numbers%10;
            numbers/=10;
            int temp1 = numbers%10;
            numbers/=10;
            odd += numbers%10;
            numbers/=10;
            temp1 *= 2;
            if(temp1 >= 10){
                temp1 = (temp1%10)+1;
            }
            numbers*=2;
            if(numbers >= 10){
                numbers = (numbers%10)+1;
            }
            even += numbers;
            even += temp1;

        }
        int sum = odd + even;
        if(sum%10 == 0){
            printf("Valid\n");
        }
        else{
            printf("Invalid\n");
        }



    }


    return 0;
}
