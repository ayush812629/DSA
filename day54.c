// Problem Statement:
// Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print traversal in zigzag order

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 1 3 2 4 5 6 7

// Explanation:
// Level 1 is printed left-to-right, level 2 right-to-left, and so on.


#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

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

    struct Node* queue[MAX];
    int front = 0, rear = -1;

    if(root) queue[++rear] = root;

    int leftToRight = 1;

    while(front <= rear) {
        int size = rear - front + 1;
        int level[size];

        for(int i = 0; i < size; i++) {
            struct Node* curr = queue[front++];
            level[i] = curr->data;

            if(curr->left) queue[++rear] = curr->left;
            if(curr->right) queue[++rear] = curr->right;
        }

        if(leftToRight) {
            for(int i = 0; i < size; i++) printf("%d ", level[i]);
        } else {
            for(int i = size - 1; i >= 0; i--) printf("%d ", level[i]);
        }

        leftToRight = !leftToRight;
    }

    return 0;
}