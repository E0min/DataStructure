#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    char key;
    struct treeNode* left;
    struct treeNode* right;
}treeNode;

treeNode* insertKey(treeNode* p, char x){
    /*트리의 루트부터 적절한 위치를 찾아가는 재귀호출실행*/
    treeNode* newNode;
    if(p == NULL){ //리프 노드 삽입 연산 
        newNode = (treeNode*)malloc(sizeof(treeNode));
        newNode -> key = x;
        newNode -> right = NULL;
        newNode -> left = NULL;
        return newNode;
    }else if(x<p->key){
        p->left = insertKey(p->left,x);
        return p;
    }else if(x> p->key){
        p -> right = insertKey(p->right,x);
        return p;
    }else{
        printf("\n 이미 같은 키가 존재 \n");
        return p;
    }
}
void insert(treeNode** root, char x){
        *root = insertKey(*root,x);
    }

    treeNode* searchBST(treeNode* root, char x){
        treeNode* p;
        p = root;
        while(p != NULL){
            if(x< p->key)
                p = p -> left;
            else if( x == p->key)
                return p;
            else p = p->right;
        }
        printf("\nThere are no such thing\n");
        return p;
    }


int main(){
        treeNode* root = NULL;
        treeNode* foundedNode = NULL;
        char key;
        insert(&root,'A');
        insert(&root,'B');
        insert(&root,'C');
        insert(&root,'D');
        insert(&root,'E');
        insert(&root,'F');
        insert(&root,'G');
        insert(&root,'H');
        insert(&root,'I');
        insert(&root,'J');
        insert(&root,'K');
        insert(&root,'L');
        insert(&root,'M');
        insert(&root,'N');
        insert(&root,'Q');

        printf("\npress letters what you want to find: ");
        scanf("%c", &key);
        while ( key != 'z')
        {
            foundedNode = searchBST(root,key);
            if(foundedNode != NULL){
                printf("\n Find key. \n",foundedNode -> key);
            }else
                printf("\n cannot find key. \n");
            scanf("%c", &key);

            printf("\n\n\n press letters what you want to find: ");
            scanf("%c", &key);
            /* code */
        }
        system("pause");
        
    }