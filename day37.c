// Problem Statement:
// Implement a Priority Queue using an array. An element with smaller value has higher priority.

// Supported Operations:
// - insert x
// - delete
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain operations

// Output Format:
// - Print the deleted or peeked element
// - Print -1 if the queue is empty

// Example:
// Input:
// 5
// insert 30
// insert 10
// insert 20
// delete
// peek

// Output:
// 10
// 20

#include <stdio.h>
#include <string.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int pq[MAX];
    int size = 0;

    for(int i = 0; i < n; i++) {
        char op[10];
        scanf("%s", op);

        if(strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            pq[size++] = x;
        } else if(strcmp(op, "delete") == 0) {
            if(size == 0) {
                printf("-1\n");
            } else {
                int min_idx = 0;
                for(int j = 1; j < size; j++) {
                    if(pq[j] < pq[min_idx]) {
                        min_idx = j;
                    }
                }
                printf("%d\n", pq[min_idx]);
                for(int j = min_idx; j < size - 1; j++) {
                    pq[j] = pq[j + 1];
                }
                size--;
            }
        } else if(strcmp(op, "peek") == 0) {
            if(size == 0) {
                printf("-1\n");
            } else {
                int min_idx = 0;
                for(int j = 1; j < size; j++) {
                    if(pq[j] < pq[min_idx]) {
                        min_idx = j;
                    }
                }
                printf("%d\n", pq[min_idx]);
            }
        }
    }

    return 0;
}