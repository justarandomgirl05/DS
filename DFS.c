#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency Matrix

int visitedMatrix[MAX];
int adjMatrix[MAX][MAX];

void dfsMatrix(int v, int n)
{
    visitedMatrix[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++)
    {
        if (adjMatrix[v][i] && !visitedMatrix[i])
        {
            dfsMatrix(i, n);
        }
    }
}

// adjacency list
struct Node
{
    int data;
    struct Node *next;
};

struct Node *adjList[MAX];
int visitedList[MAX];

void addEdgeList(int u, int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

void dfsList(int v)
{
    visitedList[v] = 1;
    printf("%d ", v);

    struct Node *temp = adjList[v];
    while (temp != NULL)
    {
        if (!visitedList[temp->data])
        {
            dfsList(temp->data);
        }
        temp = temp->next;
    }
}

int main()
{
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);

        // Fill adjacency matrix
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // if undirected

        // Fill adjacency list
        addEdgeList(u, v);
        addEdgeList(v, u); // if undirected
    }

    int start;
    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);

    printf("\nDFS using Adjacency Matrix: ");
    dfsMatrix(start, n);

    printf("\nDFS using Adjacency List: ");
    dfsList(start);

    return 0;
}
