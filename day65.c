// Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

// Output:
// - YES or NO


#include <stdio.h>

#define MAX 1000

int adj[MAX][MAX], visited[MAX], n;

int dfs(int v, int parent) {
    visited[v] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[v][i]) {
            if(!visited[i]) {
                if(dfs(i, v)) return 1;
            } else if(i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(i, -1)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");

    return 0;
}