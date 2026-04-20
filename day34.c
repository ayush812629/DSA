// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

// Input:
// - Postfix expression with operands and operators

// Output:
// - Print the integer result

// Example:
// Input:
// 2 3 1 * + 9 -

// Output:
// -4

// Explanation:
// Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    struct Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

int main() {
    char expr[1000];
    struct Node* top = NULL;

    fgets(expr, sizeof(expr), stdin);

    char* token = strtok(expr, " \n");

    while(token != NULL) {
        if(isdigit(token[0])) {
            push(&top, atoi(token));
        } else {
            int b = pop(&top);
            int a = pop(&top);
            int res;

            if(token[0] == '+') res = a + b;
            else if(token[0] == '-') res = a - b;
            else if(token[0] == '*') res = a * b;
            else if(token[0] == '/') res = a / b;

            push(&top, res);
        }
        token = strtok(NULL, " \n");
    }

    printf("%d", pop(&top));

    return 0;
}