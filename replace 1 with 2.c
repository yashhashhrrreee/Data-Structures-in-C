/*Write an algorithm Replace that takes a queue and two item. If
the first item is in the queue, replace it with the second item,
leaving the rest of the queue unchanged.*/

#include<stdio.h>
#include<stdlib.h>

#define max 20


typedef struct queue queue;

struct queue
{
	int front,rear;
	int item[max];
};


int isFull(queue *q)
{
	if(q->rear==max)
		return 1;
	return 0;
}


void replace(queue *q,int number1,int number2)
{
	int x=0,i=0,temp;
	while( x != q->rear ){
		if (q->item[x]==number1)
			q->item[x]=number2;
		x++;
	}
	printf("\n*REPLACE DONE*");
}


void menu ()
{
	printf("\n\nSelect the required option:");
	printf("\n1.Add data in queue");
	printf("\n2.Display queue");
	printf("\n3.Replace data in queue");
	printf("\n4.Exit");
	printf("\nEnter desired operation number: ");
}


void display(queue q)
{
 	int x=1;
	while(x!=q.rear)
        {
		printf("\n%d: %d",x,q.item[x]);
		x++;

	}
	printf("\nFront: %d",q.item[q.front] );
	printf("\nRear: %d",q.item[--q.rear] );
}


void enqueue(queue *q,int data)
{
	if (isFull(q))
 		printf("\nQueue is full");
 	else
 		q->item[q->rear++]=data;

}


void search(queue *q,int number1)
{
	int x=1,i=0;
	while( x < q->rear )
        {
		if (q->item[x]==number1)
		{
			++i;
		}
		x++;
	}
	if (i>0)
	{
		printf("\n%d  MATCH FOUND",i );
	}
	else
	{
		printf("\nNO MATCH FOUND\n");
		exit(0);
	}
}


int main()
{

	int n,number1,number2;
	int data;
	struct queue q;
	q.rear=q.front=1;

	while(1)
        {

		menu();
		scanf("%d",&n);
		switch(n)
		{
			case 1:
			    {
				printf("\nEnter number: ");
				scanf("%d",&data);
				enqueue(&q,data);
				break;
			}
			case 2:
			    {
				display(q);
				break;
			}
			case 3:
			    {
				printf("\nEnter number to be searched: ");
				scanf("%d",&number1);
				search(&q,number1);
				printf("\n\nEnter number to replace it with: ");
				scanf("%d",&number2);
				replace(&q,number1,number2);
				display(q);
				break;
			}
			case 4:
			    {
				exit(0);
			}
			default : printf("\nINVALID OPTION!!!");
		};
	}
	return 0;
}
