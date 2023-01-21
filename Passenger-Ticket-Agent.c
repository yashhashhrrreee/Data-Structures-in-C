#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
#define SIZE 30

struct queue
{
    char queue_name[MAX][SIZE];
    char queue_place[MAX][SIZE];
    int queue_age[MAX];
    int rear1;
    int front1;
}q1;

void enqueue(int age,char name[],char place[],int *front,int *rear,struct queue *q)
{
	if(((*front)==0&&(*rear)==MAX-1)||((*front)==(*rear)+1))
	{
		printf("Queue Overflow\n");
	}
	if( (*front) == -1 )
    {
        (*front)=0;
    }
    (*rear)=(*rear)+1;
	q->queue_age[*rear]=age;
	strcpy(&q->queue_name[*rear][0],name);
	strcpy(&q->queue_place[*rear][0],place);
}


void dequeue(struct queue *q,int *front)
{
	int age;
	char name[SIZE],place[SIZE];

	if((*front)==-1)
	{
		printf("Queue Empty\n");
	}
	age=q->queue_age[*front];
	strcpy(name,&q->queue_name[*front][0]);
	strcpy(place,&q->queue_place[*front][0]);

	printf("\n\nName: %s ,Age: %d ,Place to travel from Pune: %s",name,age,place);

	(*front)=(*front)+1;
}


void peek(int *front,struct queue *q)
{
    int age;
    char name[SIZE],place[SIZE];

	if((*front)==-1)
	{
		printf("Queue Underflow\n");
	}
	else
    {
        age=q->queue_age[*front];
        strcpy(name,&q->queue_name[*front][0]);
        strcpy(place,&q->queue_place[*front][0]);

        printf("\n\nName: %s ,Age: %d ,Place to travel from Pune: %s",name,age,place);
    }
}


void display(int *front,int *rear,struct queue *q)
{
	int i,age;
	char name[SIZE],place[SIZE];

	if ((*front)==-1)
	{
		printf("Queue is empty\n");
	}
	else
    {
        printf("Queue is :\n\n");
        i=(*front);
        if((*front)<=(*rear))
        {
            while(i<=(*rear))
            {
                age=q->queue_age[i];
                strcpy(name,&q->queue_name[i][0]);
                strcpy(place,&q->queue_place[i][0]);

                printf("\n\nName: %s ,Age: %d ,Place to travel from Pune: %s",name,age,place);
                i++;
            }

        }
        else
        {
            while(i<=MAX-1)
            {
                age=q->queue_age[i];
                strcpy(name,&q->queue_name[i][0]);
                strcpy(place,&q->queue_place[i][0]);

                printf("\n\nName: %s ,Age: %d ,Place to travel from Pune: %s",name,age,place);
                i++;
            }

            i=0;
            while(i<=(*rear))
            {
                age=q->queue_age[i];
                strcpy(name,&q->queue_name[i][0]);
                strcpy(place,&q->queue_place[i][0]);

                printf("\n\nName: %s ,Age: %d ,Place to travel from Pune: %s",name,age,place);
                i++;
            }
        }
    }
}

void main()
{
	int choice,age;
	char name[SIZE],place[SIZE];

	q1.rear1=q1.front1=-1;

	while(1)
	{
		printf("\n\n\n1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display element at the front\n");
		printf("4.Display all elements of the queue\n");
		printf("5.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1:
			printf("\n\nInput the info. of person for adding in queue : ");
			printf("\nEnter Name of person:");
			fflush(stdin);
			gets(name);
			fflush(stdin);
			printf("\nEnter Age of person:");
			scanf("%d",&age);
			fflush(stdin);
			printf("\nEnter Place person want to go from Pune:");
			fflush(stdin);
			gets(place);
			fflush(stdin);

			enqueue(age,name,place,&q1.front1,&q1.rear1,&q1);
			break;
		case 2:
			printf("\nDeleted person's info.  \n");
			dequeue(&q1,&q1.front1);
			break;
		case 3:
			printf("\nPerson at the front is :\n");
			peek(&q1.front1,&q1);
			break;
		case 4:
			display(&q1.front1,&q1.rear1,&q1);
			break;
		case 5:
			exit(0);
		default:
			printf("\nWrong choice\n");
		}
	}

}
