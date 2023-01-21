#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int id;
    int time;
} Job;

typedef struct {
    int front, rear;
    Job data[MAX_QUEUE_SIZE];
} Queue;

void init_queue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int is_empty(Queue *q) {
    return q->front > q->rear;
}

int is_full(Queue *q) {
    return q->rear == MAX_QUEUE_SIZE - 1;
}

void enqueue(Queue *q, Job x) {
    if (is_full(q)) {
        printf("Error: queue is full\n");
        return;
    }

    q->data[++q->rear] = x;
}

Job dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Error: queue is empty\n");
        exit(1);
    }

    return q->data[q->front++];
}

int main() {
    int n = 4; // fixed time quantum
    Queue q;
    init_queue(&q);

    // enqueue jobs
    Job j1 = {1, 10};
    Job j2 = {2, 7};
    Job j3 = {3, 5};
    enqueue(&q, j1);
    enqueue(&q, j2);
    enqueue(&q, j3);

    while (!is_empty(&q)) {
        Job current = dequeue(&q);
        printf("Processing job %d with remaining time %d\n", current.id, current.time);
        if (current.time > n) {
            current.time -= n;
            enqueue(&q, current);
        }
    }

    return 0;
}

