#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define MAX_VERTEX 10
#define FALSE 0
#define TRUE 1

typedef struct graphNode
{
    int vertex;
    struct graphNode *link;
} graphNode;

typedef struct graphType
{
    int n;
    graphNode *adjList_H[MAX_VERTEX];
    int visited[MAX_VERTEX];
} graphType;

/// 스택 연산

typedef struct stackNode
{
    int data;
    struct stackNode *link;
} stackNode;

stackNode *top;

void push(int item)
{
    stackNode *temp = (stackNode *)malloc(sizeof(stackNode));
    temp->data = item; // 입력받은 데이터를 데이터 필드에 저장
    temp->link = top;  // 링크필드에 이전 top의 주소를 저장
    top = temp;        // 추가된 노드의 주소가 top의 주소가 된다.
}
int pop()
{
    int item;
    stackNode *temp = top;

    if (top == NULL)
    {
        printf("\n\n Stack is empty! \n");
        return 0;
    }
    else
    {
        item = temp->data; // top이 가리키는 노드의 데이터 값 item에 저장
        top = temp->link;  // top이 가리키는 노드의 링크가 가리키는 주소가 새로운 top이 된다.
        free(temp);
        return item;
    }
}
////// 스택 연산

void createGraph(graphType *g)
{
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTEX; v++)
    {
        g->visited[v] = FALSE;
        g->adjList_H[v] = NULL;
    }
}

void insertVertex(graphType *g, int v)
{
    if (((g->n) + 1) > MAX_VERTEX)
    {
        printf("\n 그래프 정점의 개수를 초과하였습니다.");
        return;
    }
    g->n++;
}

void insertEdge(graphType *g, int u, int v)
{
    graphNode *node;            //
    if (u >= g->n || v >= g->n) // 정점에 없는거 고르는 경우
    {
        printf("\n그래프에 없는 정점입니다.");
        return;
    }
    node = (graphNode *)malloc(sizeof(graphNode)); // graphNode 포인터변수 생성후 동적 할당
    node->vertex = v;
    node->link = g->adjList_H[u]; // 인자값의 graphNode 포인터 배열의 원소를 할당
    g->adjList_H[u] = node;       // adjList는 graphNode의 포인터를 저장하는 배열이므로..
}

void print_adjList(graphType *g)
{
    int i;
    graphNode *p;
    for (i = 0; i < g->n; i++)
    {
        printf("\n\t\t정점 %c의 인접리스트", i + 65);
        p = g->adjList_H[i];
        while (p)
        {
            printf("->%c", p->vertex + 65); // 정점 0~4를 A~D로 출력
            p = p->link;
        }
    }
}

void DFS_adjList(graphType *g, int v)
{
    graphNode *w;
    top = NULL; //스택의 top을 NULL로 초기화
    push(v);
    g->visited[v] = TRUE;
    printf("%c", v + 65);
    while (top != NULL)
    {
        w = g->adjList_H[v]; //adjList[v]가 가리키는 graphNode의 주소
        while (w)
        {
            if (!g->visited[w->vertex]) // 방문하지 않은 경우
            {
                push(w->vertex); // 정점을 스택에 푸시
                g->visited[w->vertex] = TRUE; // 그 정점의 값을 visited배열에 넣고 TRUE
                printf("%c", w->vertex + 65);
                v = w->vertex; 
                w = g->adjList_H[v];
            }
            else
                w = w->link;
            /* code */
        }
        v = pop();
    }
}

void main(){
    int i;
    graphType *G9;
    G9 = (graphType*)malloc(sizeof(graphType));
    createGraph(G9);
    for(i=0;i<7;i++)
        insertVertex(G9,i);
    insertEdge(G9,0,2);
    insertEdge(G9,0,1);
    insertEdge(G9,1,4);
    insertEdge(G9,1,3);
    insertEdge(G9,1,0);
    insertEdge(G9,2,4);
    insertEdge(G9,2,0);
    insertEdge(G9,3,6);
    insertEdge(G9,3,1);
    insertEdge(G9,4,6);
    insertEdge(G9,4,2);
    insertEdge(G9,4,1);
    insertEdge(G9,5,6);
    insertEdge(G9,6,5);
    insertEdge(G9,6,4);
    insertEdge(G9,6,3);
    printf("\n G9의 인접리스트");
    print_adjList(G9);

    printf("\n\n /////////////\n\n 깊이 우선 탐색");
    DFS_adjList(G9,0);

    system("pause");













}