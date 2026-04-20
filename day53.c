// Problem Statement:
// Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

// Input Format:
// - First line contains integer N (number of nodes)
// - Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

// Output Format:
// - Print nodes column by column from leftmost to rightmost vertical line

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 4
// 2
// 1 5 6
// 3
// 7

// Explanation:
// Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.


#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Node {
    int data;
    struct Node *left, *right;
};

struct Pair {
    struct Node* node;
    int hd;
};

struct Node* newNode(int x) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = x;
    node->left = node->right = NULL;
    return node;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* nodes[n];

    for(int i = 0; i < n; i++) {
        if(arr[i] == -1) nodes[i] = NULL;
        else nodes[i] = newNode(arr[i]);
    }

    for(int i = 0; i < n; i++) {
        if(nodes[i]) {
            int l = 2*i + 1, r = 2*i + 2;
            if(l < n) nodes[i]->left = nodes[l];
            if(r < n) nodes[i]->right = nodes[r];
        }
    }

    struct Node* root = nodes[0];

    struct Pair q[MAX];
    int front = 0, rear = -1;

    int map[MAX][MAX], count[MAX] = {0};

    int offset = MAX / 2;
    int min = offset, max = offset;

    q[++rear] = (struct Pair){root, offset};

    while(front <= rear) {
        struct Pair p = q[front++];

        map[p.hd][count[p.hd]++] = p.node->data;

        if(p.node->left) {
            q[++rear] = (struct Pair){p.node->left, p.hd - 1};
            if(p.hd - 1 < min) min = p.hd - 1;
        }
        if(p.node->right) {
            q[++rear] = (struct Pair){p.node->right, p.hd + 1};
            if(p.hd + 1 > max) max = p.hd + 1;
        }
    }

    for(int i = min; i <= max; i++) {
        for(int j = 0; j < count[i]; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}