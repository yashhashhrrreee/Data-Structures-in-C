#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define m 5       //Where m is number of people a queue can hold

//Structure for having the queues in the program
typedef struct queue
{
    int ifront, irear;
    int itime[m];
    int iwait[m];
    char ch[m];
    int person;
}Queue;



//Enqueue for Q1
void enqueue(Queue *q,  int x)
{
    int imin, i = q->ifront, iwaiting=0;
    if( q->ifront == (q->irear+1)%m && q->irear!=-1 )
        printf("\nQueue %d is full", x);
    else{
        q->ch[(q->irear+1)%m] = ++q->person;
        printf("\nEnter the time taken by the person %c in Queue %d = ", q->ch[(q->irear+1)%m], x);
        scanf("%d", &imin);
        if(q->irear == -1){
            q->irear = 0;
            q->itime[q->irear] = imin;
            q->iwait[q->irear] = 0;
        }
        else{
            q->irear = (q->irear+1)%m;
            q->itime[q->irear] = imin;
            while(i != q->irear){
                iwaiting += q->itime[i];
                i = (i+1)%m;
            }
            q->iwait[q->irear] = iwaiting;
        }
        displayQueue(q,x);
   }
}

//Dequeue for Queue
int dequeue(Queue *q, int x){
    int imin=0;
    if (q->irear == -1)
        printf("\nQueue %d is empty", x);
    else {
        printf("\nThe waiting time of person %c in Queue %d was = %d", q->ch[q->ifront], x, q->iwait[q->ifront]);
        if(q->irear == q->ifront){
            imin = q->itime[q->ifront];
            q->irear = -1;
            q->ifront = 0;
            q->person = 65;
        }
        else{
            imin = q->itime[q->ifront];
            q->ifront = (q->ifront+1) % m;
            displayQueue(q,x);
        }
    }
    return imin;
}

//Display function display Queue
void displayQueue(Queue *q, int x){
    int i = q->ifront ;
    printf("\nQueue %d with its taken time and waiting time respectively is :\n",x);
    while(i != q->irear){
        printf("%c [%d] [%d]\t\t", q->ch[i], q->itime[i],q->iwait[i]);
        i = (i+1) % m;
    }
    printf("%c [%d] [%d]\t\t", q->ch[i], q->itime[i],q->iwait[i]);
}

//Function menu
void switchMenu(void)
{
    printf("\n\nChoose from the menu. Enter\n1. Enqueue to Queue 1");
    printf("\n2. Enqueue to Queue 2");
    printf("\n3. Enqueue to Queue 3");
    printf("\n4. Dequeue to Queue 1");
    printf("\n5. Dequeue to Queue 2");
    printf("\n6. Dequeue to Queue 3");
    printf("\n7. To exit the program");
    printf("\nYour choice = ");
}

//Main function
int main ()
{
    int ichoice=0;
    Queue q1, q2, q3;
    q1.ifront = q2.ifront = q3.ifront = 0, q1.irear = q2.irear = q3.irear = -1;
    q1.person = q2.person = q3.person = 64;

    printf("This a program for a bank simulation of its teller operation to see how waiting times would be affected by adding \nanother teller.\nEnqueue and dequeue to Queue 1 for simulation of one teller operation and to Queue 2 and Queue 3 for simulation of two teller operations");
    while(1)
    {
        switchMenu();
        scanf("%d",&ichoice);
        switch(ichoice)
        {
            case 1: enqueue(&q1,1);
                         break;
            case 2: enqueue(&q2,2);
                         break;
            case 3: enqueue(&q3,3);
                         break;
            case 4: dequeue(&q1,1);
                         break;
            case 5: dequeue(&q2,2);
                         break;
            case 6: dequeue(&q3,3);
                         break;
            case 7: exit(0);
            default: printf("\nWrong choice");
        }
    }
    return 0;
    
}

         
