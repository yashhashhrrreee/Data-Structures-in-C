//2 + 3 * 4 - 5
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_EXPR_SIZE 100
#define MAX_STACK_SIZE 100

typedef struct {
    char data[MAX_STACK_SIZE];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

void push(Stack *stack, char value) {
    if (!isFull(stack)) {
        stack->data[++stack->top] = value;
    }
}

char pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return '\0';
}

int getPriority(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

int performOp(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '^':
            return pow(a, b);
        default:
            return -1;
    }
}

int evaluateInfix(char *expr) {
    Stack opStack, valStack;
    initStack(&opStack);
    initStack(&valStack);

    for (int i = 0; i < strlen(expr); i++) {
        if (isdigit(expr[i])) {
            int val = 0;
            while (i < strlen(expr) && isdigit(expr[i])) {
                val = val * 10 + (expr[i] - '0');
                i++;
            }
            push(&valStack, val);
            i--;
        } else if (expr[i] == '(') {
            push(&opStack, expr[i]);
        } else if (expr[i] == ')') {
            while (!isEmpty(&opStack) && opStack.data[opStack.top] != '(') {
                int val2 = pop(&valStack);
                int val1 = pop(&valStack);
                char op = pop(&opStack);
                int result = performOp(val1, val2, op);
                push(&valStack, result);
            }
            pop(&opStack);
        } else if (strchr("+-*/^", expr[i])) {
            while (!isEmpty(&opStack) && getPriority(opStack.data[opStack.top]) >= getPriority(expr[i])) {
                int val2 = pop(&valStack);
                int val1 = pop(&valStack);
                char op = pop(&opStack);
                int result = performOp(val1, val2, op);
                push(&valStack, result);
            }
            push(&opStack, expr[i]);
        } else {
            printf("Invalid character: %c\n", expr[i]);
            return -1;
        }
    }

    while (!isEmpty(&opStack)) {
        int val2 = pop(&valStack);
        int val1 = pop(&valStack);
        char op = pop(&opStack);
        int result = performOp(val1, val2, op);
        push(&valStack, result);
    }

    return pop(&valStack);
}

int main() {
    char expr[MAX_EXPR_SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", expr);

    printf("Result: %d\n", evaluateInfix(expr));
    return 0;
}

