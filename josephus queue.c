#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

struct Node* dequeue(struct Queue* q) {
    if (q->front == NULL)
        return NULL;
    struct Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    return temp;
}

int josephus(int n, int k) {
    struct Queue* q = createQueue();
    for (int i = 1; i <= n; i++)
        enqueue(q, i);
    struct Node* temp;
    while (q->front != q->rear) {
        for (int i = 0; i < k-1; i++) {
            temp = dequeue(q);
            enqueue(q, temp->data);
        }
        temp = dequeue(q);
        printf("%d ", temp->data);
    }
    printf("\nLast person left: %d\n", q->front->data);
    return q->front->data;
}

int main() {
    int n, k;
    printf("Enter number of people and counting interval: ");
    scanf("%d %d", &n, &k);
    josephus(n, k);
    return 0;
}

