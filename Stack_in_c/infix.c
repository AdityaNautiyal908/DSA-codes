#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char c) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;
    else
        return -1; // For '(' and ')'
}

void reverse(char *exp) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(exp) - 1; i < j; i++, j--) {
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
    }
}

void infixToPrefix(char *exp) {
    char prefix[MAX_SIZE];
    int i, j;
    i = j = 0;
    reverse(exp);

    while (exp[i] != '\0') {
        if (isalnum(exp[i])) {
            prefix[j++] = exp[i];
        } else if (exp[i] == ')') {
            push(exp[i]);
        } else if (exp[i] == '(') {
            while (top != -1 && stack[top] != ')') {
                prefix[j++] = pop();
            }
            if (top == -1) {
                printf("Invalid expression: Unbalanced parentheses\n");
                exit(1);
            }
            pop(); // Discard the ')'
        } else {
            while (top != -1 && precedence(stack[top]) > precedence(exp[i])) {
                prefix[j++] = pop();
            }
            push(exp[i]);
        }
        i++;
    }

    while (top != -1) {
        if (stack[top] == ')') {
            printf("Invalid expression: Unbalanced parentheses\n");
            exit(1);
        }
        prefix[j++] = pop();
    }
    prefix[j] = '\0';
    printf("Prefix expression: ");
    reverse(prefix);
    printf("%s\n", prefix);
}

int main() {
    char exp[MAX_SIZE];
    printf("Enter infix expression: ");
    scanf("%s", exp);
    infixToPrefix(exp);
    return 0;
}
