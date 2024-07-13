#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define max(a,b) (a>b)?a:b

/*
Algorithms getK（n,p）
input 整數n 與 p
output k 滿足 k^n =p
1.  k <- 1
2. factor <- 2
3. while p > 1
4.    if p mod factor == 0
5.        k *= factor
6.        p /= pow(factor, n) #由於題目特性，出現p之因數時代表p必有n個該質因數
7.    else
8.        factor++
9. return k
*/


int mod(char* numbers, int divisor){
    //計算餘數
    int remainder = 0;
    int index = 0;
    int size = strlen(numbers);
    while(index < size){
        if(remainder < divisor){
            remainder*=10;
            remainder += (numbers[index++]-'0');

        }
        else{
            remainder %= divisor;
        }
    }
    remainder %= divisor;
    return remainder;
}

char* divide(char* numbers, int divisor){
    //以char陣列來實現多位數除法
    char* answer = (char*)calloc(102,sizeof(char));
    int answerIndex = 0;
    int remainder = 0;
    int head = 1;
    for(int index=0; index<strlen(numbers); index++){
        remainder *= 10;
        remainder += numbers[index]-'0';
        if(remainder >=  divisor){
            answer[answerIndex++] = ((int)remainder/divisor + '0');
            remainder %= divisor;
            head = 0;
        }
        else{
            if(head == 0){
                answer[answerIndex++] = '0';}
        }
    }


    return answer;

}

int main() {

    int sample;
    scanf("%d",&sample);
    while(sample--){
        int n;
        char* p = (char*)calloc(102,sizeof(char));
        scanf("%d ",&n);
        scanf("%s",p);
        getchar();
        int k = 1;
        int factor = 2;
        while(strlen(p) != 1 && p[0] != 1){
            if(mod(p,factor) == 0){
                k*=factor;
                for(int i=0; i<n; i++){
                    char* temp = p;
                    p = divide(p,factor);
                    free(temp);
                    //printf("%s\n", p);
                }
            }
            else{
                factor++;
            }


        }
        printf("%d\n",k);
        free(p);
    }




    return 0;
}
