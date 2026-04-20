// Problem: BST Search

// Implement the solution for this problem.

// Input:
// - Input specifications

// Output:
// - Output specifications


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

int search(struct Node* root, int key) {
    if(root == NULL) return 0;
    if(root->data == key) return 1;
    if(key < root->data) return search(root->left, key);
    return search(root->right, key);
}

int main() {
    int n, key;
    scanf("%d", &n);

    struct Node* root = NULL;

    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    scanf("%d", &key);

    if(search(root, key)) printf("Found");
    else printf("Not Found");

    return 0;
}