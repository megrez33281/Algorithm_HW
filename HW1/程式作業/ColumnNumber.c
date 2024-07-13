#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


int main(){
	//26base
	int Case;
	scanf("%d ",&Case);
	while(Case--){
        char Title[10];
        gets(Title);
        int TheColumn = 0;
        int product = 1;
        for(int i=strlen(Title)-1; i>=0; i--){
            int value = Title[i]-'A' + 1;
            TheColumn += value*product;
            product*=26;

        }
        printf("%d\n",TheColumn);



	}
	return 0;
}
