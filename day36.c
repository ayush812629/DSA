// Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements to enqueue)
// - Second line: n space-separated integers
// - Third line: integer m (number of dequeue operations)

// Output:
// - Print queue elements from front to rear after operations, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 30 40 50 10 20

// Explanation:
// Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.


#include <stdio.h>

#define MAX 1000

int main() {
    int n, m;
    scanf("%d", &n);

    int q[MAX];
    int front = 0, rear = -1, size = 0;

    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        rear = (rear + 1) % MAX;
        q[rear] = x;
        size++;
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        if(size > 0) {
            front = (front + 1) % MAX;
            size--;
        }
    }

    int count = size;
    int i = front;

    while(count--) {
        printf("%d ", q[i]);
        i = (i + 1) % MAX;
    }

    return 0;
}