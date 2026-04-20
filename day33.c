// Problem: Convert an infix expression to postfix notation using stack.

// Input:
// - Single line: infix expression (operands are single characters)

// Output:
// - Print the postfix expression

// Example:
// Input:
// A+B*C

// Output:
// ABC*+

// Explanation:
// Operator precedence: * > +
// Use stack to handle operator precedence and associativity


#include <stdio.h>
#include <ctype.h>

#define MAX 1000

int precedence(char c) {
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    if(c == '^') return 3;
    return 0;
}

int main() {
    char infix[MAX], stack[MAX];
    int top = -1;

    scanf("%s", infix);

    for(int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if(isalnum(c)) {
            printf("%c", c);
        } else if(c == '(') {
            stack[++top] = c;
        } else if(c == ')') {
            while(top != -1 && stack[top] != '(') {
                printf("%c", stack[top--]);
            }
            top--;
        } else {
            while(top != -1 && precedence(stack[top]) >= precedence(c)) {
                printf("%c", stack[top--]);
            }
            stack[++top] = c;
        }
    }

    while(top != -1) {
        printf("%c", stack[top--]);
    }

    return 0;
}