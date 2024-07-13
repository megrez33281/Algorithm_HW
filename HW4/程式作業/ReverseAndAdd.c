#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int IsPalindrome(int num1){
    //判斷數字是否為迴文
    int num = num1;
    int temp = 0;
    while(num1 > 0){
        temp += num1%10;
        num1/=10;
        if(num1 > 0){temp*=10;}


    }
    if(temp == num){
        return 1;
    }

    else{
        return 0;

    }



}

int reverse(int num1){
    //得到number的相反
    int temp = 0;
    while(num1 > 0){
        temp += num1%10;
        num1/=10;
        if(num1 > 0){temp*=10;}


    }
    return temp;

}

int main(){

    int Case;
    scanf("%d",&Case);
    while(Case--){
        int number;
        scanf("%d",&number);
        int amount = 1;
        number += reverse(number);
        while(IsPalindrome(number) != 1){
            amount++;
            number += reverse(number);
        }
        printf("%d %d\n",amount,number);

    }


	return 0;
}
