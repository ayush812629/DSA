// Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

#include <stdio.h>

#define MAX 1000
#define INF 1000000000

int main() {
    int n;
    scanf("%d", &n);

    int adj[MAX][MAX];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int src;
    scanf("%d", &src);

    int dist[MAX], visited[MAX] = {0};

    for(int i = 0; i < n; i++) {
        dist[i] = INF;
    }

    dist[src] = 0;

    for(int count = 0; count < n - 1; count++) {
        int u = -1, min = INF;

        for(int i = 0; i < n; i++) {
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if(u == -1) break;

        visited[u] = 1;

        for(int v = 0; v < n; v++) {
            if(adj[u][v] && !visited[v] && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}