#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define max(a,b) (a>b)?a:b

int main() {

    int times;
    scanf("%d ", &times);
    while(times--){
        int number;
        int values[2] = {0}; //value[0] = x , value[1] = constant
        char arrays[300];
        gets(arrays);
        int magnification = 1;
        int right = 1;
        int index = 1;
        int value = 0;
        for(int i=strlen(arrays)-1; i>=0; i--){
            if(arrays[i] == 'x'){
                index = 0;
                magnification = 1;
                value = 0;
                continue;
            }
            else if(arrays[i] == '='){
                if(index == 0){
                    values[index] -= max(value,1);
                }
                else{
                    values[index] += value;
                }
                right = -1;
                index = 1;
                magnification = 1;
                value = 0;
                continue;
            }
            else if(arrays[i] == '+' || arrays[i] == '-'){
                if(arrays[i] == '-'){
                    if(index == 0){
                        value = max(value,1);
                        value *= -1;
                    }
                    else{
                        value*=-1;
                    }
                }
                else{
                    if(index == 0){
                        value = max(value,1);
                    }
                }
                if(right == 1){
                    if(index == 0){
                        values[0] -= value;

                    }
                    else{
                        values[1] += value;
                    }
                }
                else{
                    if(index == 0){
                        values[0] += value;
                    }
                    else{
                        values[1] -= value;
                    }
                }
                index = 1;
                magnification = 1;
                value = 0;
                continue;
            }
            value += (arrays[i]-'0')*magnification;
            magnification*=10;

        }
        if(index == 0){
            values[0] += max(value,1);
        }
        else{
            values[1] -= value;
        }
        if(values[0] == 0 &&  values[1] == 0){
            printf("IDENTITY\n");
        }
        else if(values[0] == 0){
            printf("IMPOSSIBLE\n");
        }
        else{
            float x = (float)values[1]/values[0];
            printf("%d\n",(int)floor(x));
        }



    }
    return 0;
}
