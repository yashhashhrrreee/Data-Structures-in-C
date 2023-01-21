#include <stdio.h>
#include <stdlib.h>

// Node structure for the double linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Stack structure
struct Stack {
    struct Node* head;
    struct Node* tail;
    int size;
};

// Initialize the stack
struct Stack* initStack() {
    struct Stack* s = (struct Stack*) malloc(sizeof(struct Stack));
    s->head = NULL;
    s->tail = NULL;
    s->size = 0;
    return s;
}

// Push an element onto the stack
void push(struct Stack* s, int data) {
    struct Node* n = (struct Node*) malloc(sizeof(struct Node));
    n->data = data;
    n->prev = NULL;
    n->next = s->head;
    if (s->head != NULL) {
        s->head->prev = n;
    }
    s->head = n;
    if (s->tail == NULL) {
        s->tail = n;
    }
    s->size++;
}

// Pop an element from the stack
int pop(struct Stack* s) {
    if (s->size == 0) {
        printf("Error: Stack is empty!\n");
        return -1;
    }
    int data = s->head->data;
    struct Node* temp = s->head;
    s->head = s->head->next;
    if (s->head != NULL) {
        s->head->prev = NULL;
    }
    free(temp);
    s->size--;
    if (s->size == 0) {
        s->tail = NULL;
    }
    return data;
}

// Peek at the top element of the stack
int peek(struct Stack* s) {
    if (s->size == 0) {
        printf("Error: Stack is empty!\n");
        return -1;
    }
    return s->head->data;
}

// Check if the stack is empty
int isEmpty(struct Stack* s) {
    return (s->size == 0);
}

// Calculate the factorial of a given number using stack
int factorial(int n) {
    struct Stack* s = initStack();
    while (n > 1) {
        push(s, n);
        n--;
    }
    int result = 1;
    while (!isEmpty(s)) {
        result *= pop(s);
    }
    return result;
}

// Generate the Fibonacci series up to a given number of terms using stack
void fibonacci(int n) {
    struct Stack* s = initStack();
    int a = 0, b = 1;
    while (n > 0) {
        int c = a + b;
        push(s, c);
        a = b;
        b = c;
        n--;
    }
    while (!isEmpty(s)) {
        printf("%d ", peek(s));
        pop(s);
    }
    printf("\n");
}
void decimalToBinary(int decimal) {
    struct Stack* s = initStack();
    while (decimal > 0) {
        int remainder = decimal % 2;
        push(s, remainder);
        decimal /= 2;
    }
    while (!isEmpty(s)) {
        printf("%d", pop(s));
    }
    printf("\n");
}
int main() {
    int number;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &number);
    int fact = factorial(number);
    printf("Factorial of %d is %d\n", number, fact);

    printf("Enter the number of terms to generate in the Fibonacci series: ");
    scanf("%d", &number);
    printf("Fibonacci series of %d terms: ", number);
    fibonacci(number);

    printf("Enter a decimal number to convert to binary: ");
    scanf("%d", &number);
    printf("Binary representation of %d is: ", number);
    decimalToBinary(number);
    return 0;
}


