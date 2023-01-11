#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct stackNode{
    element data;  //데이터 필드
    struct stackNode *link;  //링크 필드
}stackNode;

stackNode* top; // top을 가리키는 포인터

void push(element item){
    stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
    temp -> data = item; // 입력받은 데이터를 데이터 필드에 저장
    temp -> link = top; // 링크필드에 이전 top의 주소를 저장
    top = temp; // 추가된 노드의 주소가 top의 주소가 된다.
}

element pop(){
    element item;
    stackNode* temp = top;

    if(top == NULL){
        printf("\n\n Stack is empty! \n");
        return 0;
    }
    else{
        item = temp -> data; // top이 가리키는 노드의 데이터 값 item에 저장
        top = temp -> link; // top이 가리키는 노드의 링크가 가리키는 주소가 새로운 top이 된다.
        free(temp);
        return item;
    }
}

element peek(){ //현재 top에 저장된 데이터를 리턴하는 함수 
    element item;

    if(top == NULL){
        printf("\n\n Stack is empty! \n");
        return 0;
    }
    else{
        item = top -> data; // 현재 top이 가리키는 노드의 데이터를 저장 
        return item;
    }
}
void del(){
    stackNode* temp;
    if(top == NULL){
        printf("\n\n Stack is empty !\n");
    }
    else{
        temp =top;
        top = top -> link;
        free(temp);
    }
}

void printStack(){
    stackNode* p =top;
    printf("\n STACK [ ");
    while(p){
        printf("%d ",p->data);
        p = p-> link;
    }
    printf("] ");
}
void main(){
    element item;
    top = NULL;
    printStack();
    push(1);
    printStack();
    push(2);
    printStack();
    push(3);
    printStack();

    item = peek();
    printStack();
    printf("peek top => %d",item);

    del();
    printStack();

    item = pop();
    printStack();
    printf("\t pop top => %d",item);

    item = pop();
    printStack();
    printf("\t pop top => %d",item);
    pop();
    system("pause");
}
