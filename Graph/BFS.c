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
}graphNode;

typedef struct graphType
{
    int n;
    graphNode *adjList_H[MAX_VERTEX];
    int visited[MAX_VERTEX];
}graphType;

