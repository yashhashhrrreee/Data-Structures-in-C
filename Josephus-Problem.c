#include <stdio.h>

typedef struct {
    int data[50];
    int front;
    int rear;
} queue;

void enqueue(queue *q, int value){
    q->data[q->rear] = value;
    q->rear++;
}

int dequeue(queue *q)
{
    q->front++;
    return q->data[q->front - 1];
}

void display(queue *q)
{
    for(int i = q->front; i < q->rear; i++)
        printf("%d ", q->data[i]);

    printf("\n");
}

void main()
{
    queue q;
    q.front = 0;
    q.rear = 0;
    int persons, skips;
    printf("How many people in a queue?\n");
    scanf("%d", &persons);
    printf("How many people to skip?\n>");
    scanf("%d", &skips);

    printf("\nInitially the state of people is ");
    for(int i = 0; i < persons; i++)
        {
        enqueue(&q, i);
        printf("%d ", i);
    }
    printf("\n\n");


    int counter = 1;
    int person;
    while(q.rear - q.front != 1)
        {
        person = dequeue(&q);

        if(counter == skips)
            {
            counter = 0;
            printf("Killed %d: ", person);
            display(&q);
        }

        else
            enqueue(&q, person);

        counter++;
    }
    printf("Last survivor is %d", dequeue(&q));
}
