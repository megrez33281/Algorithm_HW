#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>


void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;


}

int main(){

	int Case;
	scanf("%d",&Case);
	while(Case--){
        char str1[99999] = {};
        char str2[99999] = {};
        //�ˬdstr1�O�_��str2���l�r��(len2 >= len1)
        scanf("%s %s",str1,str2);
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        bool flag = true;
        int index2 = 0;
        int index1 = 0;
        if(len2 >= len1){
            while(index1 < len1){
                if(str1[index1] != str2[index2]){
                    index2++;   //�J�줣�۵��ɡA���Vstr1�����w++
                }
                else{
                    index1++;
                    index2++;   //�J��۵��ɡA����w++
                }
                if(index2 >= len2 && index1 < len1){
                    flag = false;
                    break;
                }

            }
        }
        else{
            flag = false;
        }
        if(flag){
            printf("Yes\n");
    }
        else{
            printf("No\n");
    }

	}

}
