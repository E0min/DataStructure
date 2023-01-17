#include <stdio.h>
#define TREESIZE 100

char parent(char* T,int index){
    return T[index/2];
}

char lnode(char* T, int index){
    if((index*2) > sizeof(T)/sizeof(char))
        printf("index is to big\n");
    else
        return T[index*2];
}

char Rnode(char* T, int index){
    if((index*2)+1 > sizeof(T)/sizeof(char))
        printf("index is to big\n");
    else
        return T[index*2+1];
}

char Root(char* T){
    return T[1];
}

int main(){
    char tree[TREESIZE];
    int i = 1;
    char a;
    for(a ='A';a<='Z';a++){
        tree[i]=a;
        i++;
    }
    printf("%s\n",tree);
    printf("%c\n",Root(tree));
    printf("%c\n",Rnode(tree,3));
    printf("%c\n",lnode(tree,3));
    printf("%c\n",parent(tree,3));

}