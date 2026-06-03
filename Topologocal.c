#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX], stack[MAX], top = -1;
int n, e;

void dfs(int v) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }

    stack[++top] = v;
}

int main() {
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    for (int i = 0; i < e; i++) {
        int u, v;
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    printf("Topological Order: ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }

    printf("\n");

    return 0;
}