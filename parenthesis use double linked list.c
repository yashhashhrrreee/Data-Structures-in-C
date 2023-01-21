//"(5*(3+4))/(6-1)"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
};

struct Stack {
    struct Node* top;
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

void push(struct Stack* stack, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = stack->top;
    if (stack->top != NULL)
        stack->top->prev = newNode;
    stack->top = newNode;
}

char pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Error: stack is empty\n");
        return '$';
    }
    struct Node* temp = stack->top;
    char data = temp->data;
    stack->top = temp->next;
    if (temp->next != NULL)
        temp->next->prev = NULL;
    free(temp);
    return data;
}

int isMatchingPair(char character1, char character2) {
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}

int areParenthesisBalanced(char* exp) {
    int i;
    struct Stack* stack = createStack();
    for (i = 0; i < strlen(exp); i++) {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            push(stack, exp[i]);
        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            if (stack->top == NULL)
                return 0;
            else if (!isMatchingPair(pop(stack), exp[i]))
                return 0;
        }
    }
    if (stack->top == NULL)
        return 1;
    else
        return 0;
}

int main() {
    char exp[100];
    printf("Enter an expression: ");
    scanf("%s", exp);
    if (areParenthesisBalanced(exp))
        printf("The expression is balanced\n");
    else
        printf("The expression is not balanced\n");
    return 0;
}
