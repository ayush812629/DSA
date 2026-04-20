// Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

#include <stdio.h>

#define MAX 1000

int adj[MAX][MAX], visited[MAX], stack[MAX];
int n, top = -1;

void dfs(int v) {
    visited[v] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }

    stack[++top] = v;
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
            dfs(i);
        }
    }

    while(top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}