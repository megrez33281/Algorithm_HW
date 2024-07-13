#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

float distance(int** points, int point1, int point2){
    int x = (points[point1][0] - points[point2][0])*(points[point1][0] - points[point2][0]);
    int y = (points[point1][1] - points[point2][1])*(points[point1][1] - points[point2][1]);
    float dis = pow(x+y,0.5);
    return dis;
}

int main(){

    int n;
    scanf("%d",&n);
    while(n--){
        int m;
        scanf("%d",&m);
        int** points = (int**)calloc(m,sizeof(int*));
        for(int i=0; i<m; i++){
            points[i] = (int*)calloc(2,sizeof(int)); //x,y
            scanf("%d %d",&points[i][0],&points[i][1]);
        }
        float min_distance = distance(points,0,1);
        for(int i=0; i<m; i++){
            for(int j=i+1; j<m; j++){
                float dis = distance(points,i,j);
                if(dis < min_distance){
                    min_distance = dis;
                }
            }
        }
        printf("%.3f\n",min_distance);


        free(points);
    }

    return 0;
}
