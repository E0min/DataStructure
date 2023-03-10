#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 30

typedef struct graphNode // 각 정점들의 포인터 변수가 가리키는 노드
{
    int vertex;
    struct graphNode *link;
} graphNode;

typedef struct graphType
{
    int n;                            // 정점의 갯수
    graphNode *adjList_H[MAX_VERTEX]; // 각 정점들은 다음 정점을 가리키는 포인터 변수를 가지므로 포인터 변수를 저장하는 배열 선언
} graphType;

void creategraph(graphType *g)
{
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTEX; v++)
        g->adjList_H[v] = NULL;
}

void insertVertex(graphType *g, int v) // 정점 추가 
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
    graphNode *node;
    if (u >= g->n || v >= g->n)
    {
        printf("\n그래프에 없는 정점입니다.");
        return;
    }
    node = (graphNode *)malloc(sizeof(graphNode));
    node->vertex = v;      
    node->link = g->adjList_H[u];
    g->adjList_H[u] = node;
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

void main()
{
    int i;
    graphType *G1, *G2, *G3, *G4;
    G1 = (graphType *)malloc(sizeof(graphType));
    G2 = (graphType *)malloc(sizeof(graphType));
    G3 = (graphType *)malloc(sizeof(graphType));
    G4 = (graphType *)malloc(sizeof(graphType));
    creategraph(G1);
    creategraph(G2);
    creategraph(G3);
    creategraph(G4);
    for (i = 0; i < 4; i++)
        insertVertex(G1, i);
    insertEdge(G1, 0, 3);
    insertEdge(G1, 0, 1);
    insertEdge(G1, 1, 3);
    insertEdge(G1, 1, 2);
    insertEdge(G1, 1, 0);
    insertEdge(G1, 2, 3);
    insertEdge(G1, 2, 1);
    insertEdge(G1, 3, 2);
    insertEdge(G1, 3, 1);
    insertEdge(G1, 3, 0);
    printf("\n G1의 인접 리스트");
    print_adjList(G1);

    for (i = 0; i < 3; i++)
        insertVertex(G2, i);
    insertEdge(G2, 0, 2);
    insertEdge(G2, 0, 1);
    insertEdge(G2, 1, 2);
    insertEdge(G2, 1, 0);
    insertEdge(G2, 2, 1);
    insertEdge(G2, 2, 0);
    printf("\n\n G2의 인접리스트");
    print_adjList(G2);

    for (i = 0; i < 4; i++)
        insertVertex(G3, i);
    insertEdge(G3, 0, 3);
    insertEdge(G3, 0, 1);
    insertEdge(G3, 1, 3);
    insertEdge(G3, 1, 2);
    insertEdge(G3, 2, 3);
    printf("\n\n G3의 인접 리스트");
    print_adjList(G3);

    for (i = 0; i < 3; i++)
        insertVertex(G4, i);
    insertEdge(G4, 0, 2);
    insertEdge(G4, 0, 1);
    insertEdge(G4, 1, 2);
    insertEdge(G4, 1, 0);
    printf("\n\n G4의 인접 리스트");
    print_adjList(G4);

    system("pause");
}