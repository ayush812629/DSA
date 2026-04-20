// Problem Statement:
// Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 represents NULL)
// - Third line contains two node values

// Output Format:
// - Print the LCA value

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7
// 4 5

// Output:
// 2

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int x) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = x;
    node->left = node->right = NULL;
    return node;
}

struct Node* build(int arr[], int n) {
    struct Node* nodes[n];

    for(int i = 0; i < n; i++) {
        if(arr[i] == -1) nodes[i] = NULL;
        else nodes[i] = newNode(arr[i]);
    }

    for(int i = 0; i < n; i++) {
        if(nodes[i] != NULL) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            if(l < n) nodes[i]->left = nodes[l];
            if(r < n) nodes[i]->right = nodes[r];
        }
    }

    return nodes[0];
}

struct Node* lca(struct Node* root, int a, int b) {
    if(root == NULL) return NULL;
    if(root->data == a || root->data == b) return root;

    struct Node* left = lca(root->left, a, b);
    struct Node* right = lca(root->right, a, b);

    if(left && right) return root;
    return left ? left : right;
}

int main() {
    int n, a, b;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d %d", &a, &b);

    struct Node* root = build(arr, n);

    struct Node* ans = lca(root, a, b);
    if(ans) printf("%d", ans->data);

    return 0;
}