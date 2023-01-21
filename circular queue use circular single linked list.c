#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
}*front = NULL, *rear = NULL;

void Enqueue(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    if(front == NULL && rear == NULL){
        front = rear = temp;
        rear->next = front;
    }
    else {
        rear->next = temp;
        rear = temp;
        rear->next = front;
    }
}

void Dequeue() {
    struct Node* temp = front;
    if(front == NULL) {
        printf("Queue is Empty\n");
        return;
    }
    if(front == rear) {
        front = rear = NULL;
    }
    else {
        front = front->next;
        rear->next = front;
    }
    free(temp);
}

void Display() {
    struct Node* temp = front;
    printf("Elements in Circular Queue are: ");
    while(temp->next != front) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
}

int main() {
    Enqueue(2);
    Enqueue(4);
    Enqueue(6);
    Enqueue(8);
    Display();

    Dequeue();
    Display();

    Enqueue(10);
    Display();
    return 0;
}

