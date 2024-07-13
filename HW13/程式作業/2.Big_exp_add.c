#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define max(a,b) (a>b)?a:b
#define min(a,b) (a>b)?b:a

char* multipy(char* num1, char* num2){
    //ノchar array暗猭
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int base = 0;
    char temp[3000] = {0};

    for(int i=len1-1; i>=0; i--){
        int n1 = num1[i]-'0';
        int index = base;
        int carry = 0;
        for(int j=len2-1; j>=0; j--){
            int n2 = num2[j]-'0';
            int product = n1*n2;
            product += carry;
            if(temp[index] != 0){//猔種ず甧璶计char = 0ボ沧ゎ char = '0'琌0
                product += (temp[index]-'0');
            }
            temp[index] = (product%10 + '0');
            carry = product/10;
            index++;
        }
        if(carry >0){
            temp[index] = (carry+'0');}
        base++;
    }


    int mulIndex = 0;
    char* mul = (char*)calloc(sizeof(char),3000);
    for(int i=strlen(temp)-1; i>=0; i--){
        mul[mulIndex++] = temp[i];
    }
    if(num1 != num2){
        free(num1);
        free(num2);
    }
    else{
        free(num1);
    }
    return mul;
}


char* BigExponential(int n){
    //2^nn案计╊Θ 2^(n/2)*2^(n/2)
    //2^nn计╊Θ 2^(n/2)*2^(n/2 +1)
    if(n==1){
        char* mul = (char*)calloc(sizeof(char),3000);
        mul[0] = '2';
        return mul;
    }

    if(n%2 == 0){

        return multipy(BigExponential(n/2),BigExponential(n/2));
    }
    else{
        return multipy(BigExponential(n/2),BigExponential(n/2+1));
    }

}

char* BigExponentialAddition(int m, int n){

    //2^n + 2^m = 2^m(2^(n-m) + 1) while n > m
    int bigger = (m>n)?m:n;
    int smaller = (m<n)?m:n;
    char* small = BigExponential(bigger-smaller); //n-m

    //(2^(n-m) + 1)
    int index = strlen(small)-1;
    int carry = 1;
    while(index >= 0 && carry != 0){
        carry += (small[index]-'0');
        small[index--] = (carry%10+'0');
        carry/=10;

    }

    //磷秈
    if(index <0 && carry != 0){
        char* temp = small;
        small = (char*)calloc(sizeof(char),3000);
        small[0] = '1';
        for(int i=0; i<strlen(temp); i++){
            small[i+1] = temp[i];
        }
        free(temp);
    }

    //2^m(2^(n-m) + 1)
    char* tempII = BigExponential(smaller);

    return multipy(tempII,small);

}
int main() {

    int times;
    scanf("%d",&times);
    while(times--){

        int m,n;
        scanf("%d %d",&m,&n);
        char* answer = BigExponentialAddition(m,n);
        printf("%s\n",answer);


    }
    return 0;
}
