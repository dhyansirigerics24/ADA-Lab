#include<stdio.h>
#include<limits.h>

#define Max 50

int minDistance(int dist[], int visited[], int n){
    int min = INT_MAX, index = -1;

    for(int i = 0; i < n; i++){
        if(!visited[i] && dist[i] < min){
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void printPath(int parent[], int j){
    if(parent[j] == -1){
        printf("%d ", j);
        return;
    }
    printPath(parent, parent[j]);
    printf("%d ", j);
}

void dijkstra(int graph[Max][Max], int n, int src, int dest){
    int dist[Max], visited[Max], parent[Max];

    // Initialization
    for(int i = 0; i < n; i++){
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for(int i = 0; i < n - 1; i++){
        int u = minDistance(dist, visited, n);
        if(u == -1) break;

        visited[u] = 1;

        for(int v = 0; v < n; v++){
            if(!visited[v] && graph[u][v] != 0 &&
               dist[u] != INT_MAX &&
               dist[u] + graph[u][v] < dist[v]){

                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;   // ✅ FIX: track path
            }
        }
    }

    if(dist[dest] == INT_MAX){
        printf("\nNo path exists.\n");
    } else {
        printf("\nShortest path: ");
        printPath(parent, dest);
        printf("\nTotal Cost: %d\n", dist[dest]);
    }
}

int main(){
    int n, graph[Max][Max], src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    printf("Enter destination vertex: ");
    scanf("%d", &dest);

    dijkstra(graph, n, src, dest);

    return 0;
}