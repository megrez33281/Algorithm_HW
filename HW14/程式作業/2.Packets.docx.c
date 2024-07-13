#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define max(a,b) (a>b)?a:b
#define min(a,b) (a>b)?b:a

int main() {
    //從大到小根據情況填充空格，由於高都相同，可以視為平面的填充
    while(1){
        int sum = 0;
        int sizes[6] = {0};
        int zero = 1;
        for(int i=0; i<6; i++){
            scanf("%d", &sizes[i]);
            if(sizes[i] != 0){
                zero = 0;
            }
        }
        if(zero == 1){
            break;
        }
        sum += sizes[5];
        if(sizes[4] > 0){
            sum += sizes[4];
            sizes[4]=0;
            sizes[0]-= 11;
            if(sizes[0] < 0){
                sizes[0] = 0;
            }
        }
        if(sizes[3] > 0){
            sum += sizes[3];
            if(sizes[1] >= sizes[3]*5){
                sizes[1] -= sizes[3]*5;
            }
            else{
                sizes[0] -= (sizes[3]*5-sizes[1])*4;
                if(sizes[0] < 0){
                    sizes[0] = 0;
                }
                sizes[1] = 0;
                sizes[3] = 0;
            }
        }
        if(sizes[2] >= 4){
            sum += sizes[2]/4;
            sizes[2]%=4;
        }
        while(sizes[2] > 0){
            sum++;
            if(sizes[2] == 3){
                sizes[2] = 0;
                if(sizes[1] > 0){
                    sizes[1]--;
                    sizes[0]-=5;
                    if(sizes[1] < 0){
                        sizes[1] = 0;
                    }
                    if(sizes[0] < 0){
                        sizes[0] = 0;
                    }
                }
                else{
                    sizes[0] -= 9;
                    if(sizes[0] < 0){
                        sizes[0] = 0;
                    }
                }
            }
            else if(sizes[2] == 2){
                sizes[2] = 0;
                if(sizes[1] > 0){
                    if(sizes[1] >= 3){
                        sizes[1] -= 3;
                        sizes[0] -= 6;
                        if(sizes[0] < 0){
                            sizes[0] = 0;
                        }

                    }
                    else{
                        sizes[0] -= (3-sizes[1])*4;
                        sizes[0] -= 6;
                        sizes[1] = 0;
                        if(sizes[0] < 0){
                            sizes[0] = 0;
                        }
                    }
                }
            }
            else if(sizes[2] == 1){
                sizes[2] = 0;
                if(sizes[1] >= 5){
                    sizes[1] -= 5;
                    sizes[0] -= 7;
                    if(sizes[0] < 0){
                        sizes[0] = 0;
                    }
                }
                else{
                    sizes[0] -= (5-sizes[1])*4;
                    sizes[0] -= 7;
                    sizes[1] = 0;
                    if(sizes[0] < 0){
                        sizes[0] = 0;
                    }
                }
            }

        }

        if(sizes[1] >= 9){
            sum += (sizes[1]/9);
            sizes[1] = sizes[1]%9;
        }
        while(sizes[1] > 0){
            sizes[0] -= (9-sizes[1])*4;
            sizes[1] = 0;
            if(sizes[0] < 0){
                sizes[0] = 0;
            }
        }
        if(sizes[0] >= 36){
            sum += (sizes[0]/36);
            sizes[0] = sizes[0]%36;
        }
        if(sizes[0] > 0){
            sum ++;
            sizes[0] = 0;
        }
        printf("%d\n",sum);
    }


    return 0;
}
