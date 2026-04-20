// Problem Statement:
// Implement a Min Heap using an array where the smallest element is always at the root.

// Supported Operations:
// - insert x
// - extractMin
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain heap operations

// Output Format:
// - Print results of extractMin and peek
// - Print -1 if operation cannot be performed

// Example:
// Input:
// 6
// insert 40
// insert 10
// insert 30
// peek
// extractMin
// peek

// Output:
// 10
// 10
// 30


#include <stdio.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify_up(int i) {
    while(i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapify_down(int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < size && heap[l] < heap[smallest]) smallest = l;
    if(r < size && heap[r] < heap[smallest]) smallest = r;

    if(smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify_down(smallest);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        char op[20];
        scanf("%s", op);

        if(strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            heap[size] = x;
            heapify_up(size);
            size++;
        } else if(strcmp(op, "extractMin") == 0) {
            if(size == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", heap[0]);
                heap[0] = heap[size - 1];
                size--;
                heapify_down(0);
            }
        } else if(strcmp(op, "peek") == 0) {
            if(size == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", heap[0]);
            }
        }
    }

    return 0;
}