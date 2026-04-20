// Problem: Detect cycle in directed graph using DFS and recursion stack.

// Output:
// - YES if cycle exists

#include <stdio.h>

#define MAX 1000

int adj[MAX][MAX], visited[MAX], recStack[MAX], n;

int dfs(int v) {
    visited[v] = 1;
    recStack[v] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[v][i]) {
            if(!visited[i] && dfs(i)) return 1;
            else if(recStack[i]) return 1;
        }
    }

    recStack[v] = 0;
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
            if(dfs(i)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");

    return 0;
}