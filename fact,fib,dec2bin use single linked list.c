#include <stdio.h>
#include <stdlib.h>

// Define a stack node structure
struct StackNode {
    int data;
    struct StackNode* next;
};

// Stack operations

struct StackNode* createNewNode(int data) {
    struct StackNode* newNode = (struct StackNode*) malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(struct StackNode* root) {
    return !root;
}

void push(struct StackNode** root, int data) {
    struct StackNode* newNode = createNewNode(data);
    newNode->next = *root;
    *root = newNode;
    printf("%d pushed to stack\n", data);
}

int pop(struct StackNode** root) {
    if (isEmpty(*root))
        return -1;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int peek(struct StackNode* root) {
    if (isEmpty(root))
        return -1;
    return root->data;
}

// Factorial using stack
int factorial(int n) {
    struct StackNode* stack = NULL;
    int result = 1;
    while (n) {
        push(&stack, n);
        n--;
    }
    while (!isEmpty(stack)) {
        result *= pop(&stack);
    }
    return result;
}

// Fibonacci series using stack
void fibonacci(int n) {
    struct StackNode* stack = NULL;
    int a = 0, b = 1, c;
    push(&stack, b);
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
        push(&stack, c);
    }
    while (!isEmpty(stack)) {
        printf("%d ", pop(&stack));
    }
}

// Decimal to binary conversion using stack
void decimalToBinary(int n) {
    struct StackNode* stack = NULL;
    while (n) {
        push(&stack, n % 2);
        n /= 2;
    }
    while (!isEmpty(stack)) {
        printf("%d", pop(&stack));
    }
}

int main() {
    int n;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &n);
    printf("Factorial of %d is %d\n", n, factorial(n));
    printf("\nEnter a number to generate Fibonacci series: ");
    scanf("%d", &n);
    printf("Fibonacci series of %d is: ", n);
    fibonacci(n);
    printf("\nEnter a number to convert it to binary:");
    scanf("%d", &n);
    printf("Binary of %d is: ", n);
    decimalToBinary(n);
    return 0;
}
