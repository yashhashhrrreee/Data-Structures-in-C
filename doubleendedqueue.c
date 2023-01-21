#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int deque[MAX_SIZE];
int front = -1, rear = -1;

void insert_at_front(int item) {
    if (front == 0 && rear == MAX_SIZE - 1) {
        printf("Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX_SIZE - 1;
    } else {
        front--;
    }

    deque[front] = item;
}

void insert_at_rear(int item) {
    if (front == 0 && rear == MAX_SIZE - 1) {
        printf("Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX_SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }

    deque[rear] = item;
}

void delete_from_front() {
    if (front == -1) {
        printf("Underflow\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX_SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

void delete_from_rear() {
    if (front == -1) {
        printf("Underflow\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX_SIZE - 1;
    } else {
        rear--;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    int i;
    if (rear >= front) {
        for (i = front; i <= rear; i++) {
            printf("%d ", deque[i]);
        }
    } else {
        for (i = front; i < MAX_SIZE; i++) {
            printf("%d ", deque[i]);
        }

        for (i = 0; i <= rear; i++) {
            printf("%d ", deque[i]);
        }
    }

    printf("\n");
}

int main() {
    insert_at_rear(1);
    insert_at_rear(2);
    insert_at_rear(3);
    insert_at_front(4);
    insert_at_front(5);
    display();
    delete_from_front();
    delete_from_rear();
    display();
    return 0;
}
