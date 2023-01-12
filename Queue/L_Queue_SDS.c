#include <stdio.h>
#include <stdlib.h>
#define Q_SIZE 100

typedef char element;
typedef struct {
    element queue [Q_SIZE];
    int front,rear;
}QueueType;

QueueType *createQueue(){
    QueueType *Q;
    Q = (QueueType*)malloc(sizeof(QueueType));
    Q -> front = -1;
    Q -> rear = -1;
    return Q;
}

int isEmpty(QueueType *Q){
    if (Q -> front == Q -> rear){
        printf("\n Queue is Empty ! \n");
        return 1;
    }
    else
        return 0;
}
int isFull(QueueType *Q){
    if(Q->rear == Q_SIZE-1){
        printf("\n Queue is Full ! \n");
        return 1;
    }
    else
        return 0;
}
void enQueue(QueueType *Q, element item){
    if(isFull(Q))
        exit(1);
    else{
        Q -> rear++;
        Q -> queue[Q ->rear] = item;
    }
}
element deQueue(QueueType *Q){
    if(isEmpty(Q)) exit(1);
    else{
        Q ->front++;
        return Q -> queue[Q -> front];
    }
}
element peek(QueueType *Q){
    if(isEmpty(Q)) exit(1);
    else return Q ->queue[Q ->front+1];
}
void printQ(QueueType *Q){
    int i;
    printf("\n Queue: [ ");
    for(i = Q->front+1;i <= Q ->rear;i++)
        printf("%3c ",Q ->queue[i]);
    printf(" ]");
}

int main(){
    QueueType *Q1 = createQueue();
    element data;
    enQueue(Q1,'A');
    printQ(Q1);
    enQueue(Q1,'B');
    printQ(Q1);
    deQueue(Q1);
    printQ(Q1);
    enQueue(Q1,'C');
    printQ(Q1);
    data = peek(Q1);
    printf("\n peek item: %c",data);
    deQueue(Q1);
    printQ(Q1);
    deQueue(Q1);
    printQ(Q1);
    system("pause");
    return 0;

}
