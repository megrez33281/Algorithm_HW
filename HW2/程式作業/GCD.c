#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(){

    int Case;
    scanf("%d",&Case);
    while(Case--){
        int a,b;
        scanf("%d %d",&a,&b);
        int r =a%b;
        while(r > 0){
            a = b;
            b = r;
            r = a%b;
        }
        printf("%d\n",b);

    }
	return 0;
}
