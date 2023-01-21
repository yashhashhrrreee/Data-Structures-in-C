//23*5+
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Error: stack overflow\n");
        return;
    }
    top++;
    stack[top] = value;
}

int pop() {
    if (top == -1) {
        printf("Error: stack underflow\n");
        return -1;
    }
    int value = stack[top];
    top--;
    return value;
}

int evaluate(char* expression) {
    for (int i = 0; i < strlen(expression); i++) {
        if (isdigit(expression[i])) {
            push(expression[i] - '0');
        } else {
            int value1 = pop();
            int value2 = pop();
            switch (expression[i]) {
                case '+':
                    push(value2 + value1);
                    break;
                case '-':
                    push(value2 - value1);
                    break;
                case '*':
                    push(value2 * value1);
                    break;
                case '/':
                    push(value2 / value1);
                    break;
                default:
                    printf("Error: invalid operator\n");
                    return -1;
            }
        }
    }
    return pop();
}

int main() {
    char expression[MAX_SIZE];
    printf("Enter a postfix expression: ");
    scanf("%s", expression);
    int result = evaluate(expression);
    printf("Result: %d\n", result);
    return 0;
}

