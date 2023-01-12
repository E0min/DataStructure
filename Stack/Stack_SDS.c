#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

void push(element item) { // top에 자료를 저장
	if (top >= MAX_STACK_SIZE) {
		printf("\n\n Stack is Full!\n");
		return;
	}
	else
		stack[++top] = item;
}

element pop() { //top에 저장된 자료를 출력, 삭제
	if (top == -1) {
		printf("\n\n Stack is Empty!\n");
		return 0;
	}
	else return stack[top--];
}

void del() { // 
	if (top == -1) {
		printf("\n\n Stack is Empty!\n");
		exit(1);
	}
	else top--;
}

element peek() { // 현재의 top을 출력
	if (top == -1) {
		printf("\n\n Stack is Empty!\n");
		exit(1);
	}
	else return stack[top];
}

void printStack(){
    int i;
    printf("\nSTACK [ ");
    for(i=0;i<=top;i++)
        printf("%d ",stack[i]);
    printf("] ");
}

void main(){
    int item;
    printStack();
    push(1);
    printStack();
    push(2);
    printStack();
    push(3);
   

    item = peek();
    printStack();
    printf("peek top => %d",item);

    del();
    printStack();

    item = pop();
    printStack();
    printf(" \t pop top => %d",item);

    item = pop();
    printStack();
    printf(" \t pop top => %d",item);

    pop();
    getchar();
}