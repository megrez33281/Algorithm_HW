#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


int Ugly(int n){

   if(n <= 2){return 1;}
   else if(n%2 != 0 && n%3 != 0 && n%5 != 0){return 0;}

   for(int i=2; i<=floor(pow(n,0.5)); i++){
        if(n%i == 0 ){
            int temp = n/i;
            if(i%2!=0 && i%3!=0 && i%5!=0){
                return 0;}
            else if(temp%2!=0 && temp%3!=0 && temp%5!=0 ){
                return 0;
            }
        }

   }
    return 1;
}


int main(){
    int UglyNumber[1001] = {0};
    int index = 1;
    int i = 1;
    int n;
    scanf("%d",&n);
    while(n--){

        int N;
        scanf("%d",&N);
        if(UglyNumber[N] != 0){
            printf("%d\n",UglyNumber[N]);}
        else{
            while(index <= N){
                if(Ugly(i) == 1){
                    UglyNumber[index++] = i;
                }
                i++;
            }
            printf("%d\n",UglyNumber[N]);
        }

    }
    return 0;
}
