// Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).


#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int adj[MAX][MAX], indegree[MAX] = {0};

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
            if(adj[i][j]) indegree[j]++;
        }
    }

    int queue[MAX], front = 0, rear = -1;

    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            queue[++rear] = i;
        }
    }

    while(front <= rear) {
        int v = queue[front++];
        printf("%d ", v);

        for(int i = 0; i < n; i++) {
            if(adj[v][i]) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    queue[++rear] = i;
                }
            }
        }
    }

    return 0;
}