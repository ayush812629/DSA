// Problem Statement
// Find shortest distances from source vertex in a weighted graph with non-negative weights.

// Input Format
// n m
// u v w
// source

// Output Format
// Distances to all vertices.

// Sample Input
// 5 6
// 1 2 2
// 1 3 4
// 2 3 1
// 2 4 7
// 3 5 3
// 4 5 1
// 1

// Sample Output
// 0 2 3 9 6

// Explanation
// Shortest distances computed via priority queue.


#include <stdio.h>

#define MAX 1000
#define INF 1000000000

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[MAX][MAX];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            adj[i][j] = INF;
        }
    }

    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int src;
    scanf("%d", &src);

    int dist[MAX], visited[MAX] = {0};

    for(int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    dist[src] = 0;

    for(int count = 1; count <= n; count++) {
        int u = -1, min = INF;

        for(int i = 1; i <= n; i++) {
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        for(int v = 1; v <= n; v++) {
            if(adj[u][v] != INF && !visited[v] && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}