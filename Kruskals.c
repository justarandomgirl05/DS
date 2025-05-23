#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int parent[MAX];

struct Edge
{
    int src, dest, weight;
};

int find(int i)
{
    while (i != parent[i])
        i = parent[i];
    return i;
}

void unionSet(int u, int v)
{
    int pu = find(u);
    int pv = find(v);
    parent[pu] = pv;
}

int main()
{
    int n, i, j, k = 0;
    struct Edge edges[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n];

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
            if (i < j && adj[i][j] != 0)
            {
                edges[k].src = i;
                edges[k].dest = j;
                edges[k].weight = adj[i][j];
                k++;
            }
        }
    }

    // Sort edges by weight (Bubble Sort for simplicity)
    for (i = 0; i < k - 1; i++)
    {
        for (j = 0; j < k - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Initialize parent
    for (i = 0; i < n; i++)
        parent[i] = i;

    printf("\nEdges in the Minimum Spanning Tree:\n");
    int minCost = 0;
    for (i = 0; i < k; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;

        if (find(u) != find(v))
        {
            printf("%d - %d : %d\n", u, v, edges[i].weight);
            minCost += edges[i].weight;
            unionSet(u, v);
        }
    }

    printf("Total cost of MST: %d\n", minCost);
    return 0;
}
