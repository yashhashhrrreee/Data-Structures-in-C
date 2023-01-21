#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Deque {
    struct Node* front;
    struct Node* rear;
};

void initDeque(struct Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

int isEmpty(struct Deque* deque) {
    return deque->front == NULL;
}

void addFront(struct Deque* deque, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;

    if (isEmpty(deque)) {
        newNode->next = NULL;
        deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
    }
    deque->front = newNode;
}

void addRear(struct Deque* deque, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(deque)) {
        newNode->prev = NULL;
        deque->front = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
    }
    deque->rear = newNode;
}

void deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }
    struct Node* temp = deque->front;
    if (deque->front == deque->rear) {
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        deque->front = deque->front->next;
        deque->front->prev = NULL;
    }
    free(temp);
}

void deleteRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }
    struct Node* temp = deque->rear;
    if (deque->front == deque->rear) {
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        deque->rear = deque->rear->prev;
        deque->rear->next = NULL;
    }
    free(temp);
}

void display(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }
        struct Node* temp = deque->front;
    printf("Deque: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Deque deque;
    initDeque(&deque);

    addFront(&deque, 1);
    addFront(&deque, 2);
    addRear(&deque, 3);
    addRear(&deque, 4);
    display(&deque);

    deleteFront(&deque);
    deleteRear(&deque);
    display(&deque);

    return 0;
}


