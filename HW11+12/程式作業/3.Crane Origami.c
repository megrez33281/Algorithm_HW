#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define max(a,b) (a>b)?a:b
#define min(a,b) (a>b)?b:a

int main() {

    int Cases;
    while(scanf("%d",&Cases) != EOF){
        if(Cases == 0){
            break;
        }
        int best = 0;
        float biggest = 0;
        for(int i=1; i<= Cases; i++){
            int width,height;
            scanf("%d %d",&width,&height);
            int longer = max(width,height);
            int shorter = min(width,height);
            //����إi�檺���Ω񦡡A�@�ӬO����U���@�M�A�t�@�ӬO�̪��������M�A��ܨ�ؤ覡���i�o���j����̨Ӥ��
            float method1 =  min((float)width/2, (float)height/2);
            float method2 =  min((float)(longer/4), shorter);
            float size = max(method1,method2);
            if(size > biggest){
                biggest = size;
                best = i;
            }
        }
        printf("%d\n",best);

    }
    return 0;
}
