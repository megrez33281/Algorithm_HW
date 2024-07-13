#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define max(a,b) (a>b)?a:b
#define min(a,b) (a>b)?b:a

struct Node{

    int value;
    char* locate;
    struct Node* left;
    struct Node* right;

};

struct Node* CreateNode(int value, char* locate){

    struct Node* node  = (struct Node*)malloc(sizeof(struct Node)*1);
    node->value = value;
    node->locate = locate;
    node->left = NULL;
    node->right = NULL;
    return node;
};

int smaller(char* locate1, char* locate2){

    if(locate1[0] == ' '){
        return 1;
    }
    else if(locate2[0] == ' '){
        return 0;
    }
    else if(locate1[0] == ' ' && locate2[0] == ' '){
        return 2;
    }
    int len1=strlen(locate1);
    int len2=strlen(locate2);
    if(len1 < len2){
        return 1;
    }
    else if(len1 > len2){
        return 0;
    }

    else{
        for(int i=0; i<len1; i++){
            if(locate1[i] == 'L' && locate2[i] == 'R'){
                return 1;
            }
            else if(locate1[i] == 'R' && locate2[i] == 'L'){
                return 0;
            }
        }
        return 2;

    }


}


int main() {

    int times;
    scanf("%d",&times);
    while(times--){
        struct Node** nodes = (struct Node**)malloc(sizeof(struct Node*)*256);
        char** locates = (char**)malloc(sizeof(char*)*256);
        for(int i=0; i<256; i++){
            nodes[i] = NULL;
            locates[i] = (char*)calloc(sizeof(char),9);
        }
        char words[100];
        int index = 0;
        while(scanf("%s",words) != EOF){
            int len = strlen(words);
            if(len == 2){
                break;
            }
            int comma = 0;
            while(words[comma] != ','){
                comma++;
            }

            int factor = 1;
            int number = 0;
            for(int i=comma-1; i>0; i--){
                number += (words[i]-'0')*factor;
                factor*=10;
            }
            if(len-2 == comma){
                locates[index][0] = ' ';

            }
            else{
                for(int i=comma+1; i<len-1; i++){
                    locates[index][i-comma-1] = words[i];
                }
            }

            nodes[index] = CreateNode(number,locates[index]);
            index++;
        }
        //用bubble sort 將nodes排成能建tree的狀態
        int NotComplete = 0;
        for(int i=index-1; i>1; i--){
            if(NotComplete == 1){
                break;
            }
            for(int j=0; j<i; j++){
                if(smaller(nodes[j]->locate,nodes[j+1]->locate) == 2){
                    //出現相同位置的nodes，表示tree不可能建成
                    NotComplete = 1;
                    break;
                }
                else if(smaller(nodes[j]->locate,nodes[j+1]->locate) == 0){
                    struct Node* temp = nodes[j];
                    nodes[j] = nodes[j+1];
                    nodes[j+1] = temp;
                }
            }
        }
        if(NotComplete == 1){
            printf("not complete\n");
        }
        else{
            struct Node* root = NULL;
            for(int i=0; i<index; i++){
                if(nodes[i]->locate[0] == ' '){
                    root = (struct Node*)malloc(sizeof(struct Node)*1);
                }
                if(root == NULL){
                    NotComplete = 1;
                    break;
                }
                struct Node* pointer = root;
                int j=0;
                for(; j<strlen(nodes[i]->locate)-1; j++){
                    if(nodes[i]->locate[j] == 'L'){
                        pointer = pointer->left;
                    }
                    else if(nodes[i]->locate[j] == 'R'){
                        pointer = pointer->right;
                    }
                    if(pointer == NULL){
                        NotComplete = 1; //放置位置之根節點不存在，tree建不起來
                        break;
                    }
                }
                if(pointer == NULL){
                        NotComplete = 1;//放置位置之根節點不存在，tree建不起來
                        break;
                    }
                if(nodes[i]->locate[j] == 'L'){
                        pointer->left = nodes[i];
                    }
                else if(nodes[i]->locate[j] == 'R'){
                        pointer->right = nodes[i];
                    }

            }
            if(NotComplete == 1){
                printf("not complete\n");
            }
            else{
                for(int i=0; i<index-1; i++){
                    printf("%d ", nodes[i]->value);
                }
                printf("%d\n", nodes[index-1]->value);
            }



        }
        free(nodes);
        free(locates);
    }


    return 0;
}
