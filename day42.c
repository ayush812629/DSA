// Problem Statement:
// Given a queue of integers, reverse the queue using a stack.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers

// Output Format:
// - Print the reversed queue

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 50 40 30 20 10

#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int queue[MAX], stack[MAX];
    int front = 0, rear = -1, top = -1;

    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        queue[++rear] = x;
    }

    while(front <= rear) {
        stack[++top] = queue[front++];
    }

    int idx = 0;
    while(top != -1) {
        queue[idx++] = stack[top--];
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}