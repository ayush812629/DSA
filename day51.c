// Problem Statement:
// Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers
// - Third line contains two node values

// Output Format:
// - Print the LCA value

// Example:
// Input:
// 7
// 6 2 8 0 4 7 9
// 2 8

// Output:
// 6

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

struct Node* insert(struct Node* root, int x) {
    if(root == NULL) return newNode(x);
    if(x < root->data) root->left = insert(root->left, x);
    else root->right = insert(root->right, x);
    return root;
}

struct Node* lca(struct Node* root, int a, int b) {
    if(root == NULL) return NULL;

    if(a < root->data && b < root->data)
        return lca(root->left, a, b);
    if(a > root->data && b > root->data)
        return lca(root->right, a, b);

    return root;
}

int main() {
    int n, a, b;
    scanf("%d", &n);

    struct Node* root = NULL;

    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    scanf("%d %d", &a, &b);

    struct Node* ans = lca(root, a, b);
    if(ans) printf("%d", ans->data);

    return 0;
}