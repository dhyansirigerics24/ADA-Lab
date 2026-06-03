#include <stdio.h>

struct Edge {
    int src, dest, weight;
};

int parent[100];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int a, int b) {
    parent[a] = b;
}

void sortEdges(struct Edge edges[], int e) {
    int i, j;
    struct Edge temp;

    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main() {
    int v, e, i;
    
    printf("Enter number of vertices: ");
    scanf("%d", &v);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    struct Edge edges[e];

    printf("\nEnter Source Destination Weight for each edge:\n");
    for (i = 0; i < e; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d",
              &edges[i].src,
              &edges[i].dest,
              &edges[i].weight);
    }

    for (i = 0; i < v; i++)
        parent[i] = i;

    sortEdges(edges, e);

    printf("\nEdges in Minimum Spanning Tree:\n");

    int count = 0, minCost = 0;

    for (i = 0; i < e && count < v - 1; i++) {
        int u = find(edges[i].src);
        int w = find(edges[i].dest);

        if (u != w) {
            printf("%d -- %d  Weight = %d\n",
                   edges[i].src,
                   edges[i].dest,
                   edges[i].weight);

            minCost += edges[i].weight;
            unionSet(u, w);
            count++;
        }
    }

    printf("\nMinimum Cost = %d\n", minCost);

    return 0;
}