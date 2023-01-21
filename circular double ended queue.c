#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Deque {
    int arr[MAX_SIZE];
    int front;
    int rear;
    int count;
};

void init(struct Deque *deque) {
    deque->front = 0;
    deque->rear = MAX_SIZE - 1;
    deque->count = 0;
}

int isFull(struct Deque *deque) {
    return deque->count == MAX_SIZE;
}

int isEmpty(struct Deque *deque) {
    return deque->count == 0;
}

void insertFront(struct Deque *deque, int item) {
    if (isFull(deque)) {
        printf("Error: Deque is full\n");
        return;
    }
    deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
    deque->arr[deque->front] = item;
    deque->count++;
}

void insertRear(struct Deque *deque, int item) {
    if (isFull(deque)) {
        printf("Error: Deque is full\n");
        return;
    }
    deque->rear = (deque->rear + 1) % MAX_SIZE;
    deque->arr[deque->rear] = item;
    deque->count++;
}

int removeFront(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Error: Deque is empty\n");
        return -1;
    }
    int item = deque->arr[deque->front];
    deque->front = (deque->front + 1) % MAX_SIZE;
    deque->count--;
    return item;
}

int removeRear(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Error: Deque is empty\n");
        return -1;
    }
    int item = deque->arr[deque->rear];
    deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
    deque->count--;
    return item;
}

int main() {
    struct Deque deque;
    init(&deque);
    insertFront(&deque, 1);
    insertRear(&deque, 2);
    insertFront(&deque, 3);
    insertRear(&deque, 4);
    printf("%d\n", removeFront(&deque));  // Output: 3
    printf("%d\n", removeRear(&deque));   // Output: 4
    return 0;
}

