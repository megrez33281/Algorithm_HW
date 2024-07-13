#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define max(a,b) (a>b)?a:b
#define min(a,b) (a>b)?b:a

struct Node{

    char character;
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* CreateNode(char character, int value){

    struct Node* node = (struct Node*)malloc(sizeof(struct Node)*1);
    node->character = character;
    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;

}



int isLeaf(struct Node* node){

    return node->left == NULL && node->right == NULL;
}

void preorder(struct Node* root, char* code, struct Node** element){

    if(isLeaf(root)){
        int index = 0;
        while(element[index] != NULL){
            index++;
        }
        element[index] = root;
        int bin = 0;
        int factor = 1;
        for(int i=strlen(code)-1; i>=0; i--){
            if(code[i] == '1'){
                bin += factor;
            }
            factor*=2;
        }
        element[index]->value = bin;
        free(code);
    }

    if(root->left != NULL){
        char* leftCode= (char*)calloc(sizeof(char),100);
        int len = strlen(code);
        for(int i=0; i<len; i++){
            leftCode[i] = code[i];
        }
        leftCode[len] = '0';
        preorder(root->left,leftCode,element);

    }
    if(root->right != NULL){
        char* rightCode= (char*)calloc(sizeof(char),100);
        int len = strlen(code);
        for(int i=0; i<len; i++){
            rightCode[i] = code[i];
        }
        rightCode[len] = '1';
        preorder(root->right,rightCode,element);

    }




}

void QuickSort(struct Node** node, int start, int end){

    if(start >= end){
        return;
    }

    int pivot = node[start]->value;
    int left = start;
    int right = end;

    while(left < right){

        while(left < right && node[right]->value >pivot){

            right--;
        }
        while(left < right && node[left]->value <= pivot){
            left++;
        }

        if(left != right){
            struct Node* temp = node[left];

            node[left] = node[right];
            node[right] = temp;
        }
    }

    struct Node* temp = node[start];
    node[start] = node[left];
    node[left] = temp;
    QuickSort(node,start,right-1);
    QuickSort(node,right+1,end);

}

void PrintBinary(int n){

    if(n == 0){

        return;
    }

    PrintBinary(n/2);
    if(n%2 == 0){
        printf("0");
    }
    else{
        printf("1");
    }


}

int main() {

    struct Node** nodes = (struct Nodes**)malloc(sizeof(struct Nodes*)*999);
    char words[101] = {};
    scanf("%s",words);
    int index = 0;
    int len = strlen(words);
    int start = 0;
    for(int i=0; i<len; i++){
        int put = 0;
        for(int j=0; j<index; j++){
            if(nodes[j]->character == words[i]){
                nodes[j]->value++;
                put = 1;
                break;
            }
        }
        if(put == 0){
            nodes[index++] = CreateNode(words[i],1);
        }
    }

    int sum = index;
    QuickSort(nodes,0,index-1);

    if(nodes[0]->value == len){
        printf("%c:%d\n",nodes[0]->character,0);
    }
    else{

        struct Node* root = CreateNode('!',nodes[0]->value + nodes[1]->value);
        root->left = nodes[0];
        root->right = nodes[1];
        nodes[index++] = root;

        while(root->value != len){
            start+=2;
            QuickSort(nodes,start,index-1);
            root = CreateNode('!',nodes[start]->value + nodes[start+1]->value);
            root->left = nodes[start];
            root->right = nodes[start+1];
            nodes[index++] = root;
        }
        char* code = (char*)calloc(sizeof(char),100);
        struct Node** element = (struct Nodes**)malloc(sizeof(struct Nodes*)*sum);
        for(int i=0; i<sum; i++){
            element[i] = NULL;
        }
        preorder(root, code,element);
        QuickSort(element,0,sum-1);
        for(int i=0; i<sum; i++){
            printf("%c:",element[i]->character);
            if(element[i]->value == 0){
                printf("0");
            }
            else{
                PrintBinary(element[i]->value);}
            printf("\n");
        }
        free(element);
    }



    free(nodes);
    return 0;
}
