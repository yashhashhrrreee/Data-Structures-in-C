/*Problem Statement -WAP for A bank simulation of its teller operation to see how 
waiting times would be affected by adding another teller.*/

#include<stdio.h>
#include<stdlib.h>

struct queue
{
float que[100];
int top;
}q;

void push(float item)
{
int i,temp=0;
q.top++;
q.que[q.top] = item;
}

void pop()
{
int i;
for(i=0;i<q.top;i++)
    q.que[i]=q.que[i+1];
q.top--;
}

int main()
{
    q.top=-1;
    int cust[100],i,j;
    float n,t=0,T[100];
    printf("\n\nEnter the number of customers at the bank : ");
    scanf("%f",&n);
    printf("\nEnter the time(minitues) required for each customer to finish their work: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&cust[i]);
        push(cust[i]);
    }
            printf("\n\nWaiting time for 1 teller : \n");
            T[0]=0;
            for(i=0,j=1;i<n;i++,j++)
            {
                t=q.que[i]/10;
                if(t<1)
                    t=1;
                T[j]=t;
            }
            printf("\n\nJob\t\tWaiting time(in minutes)\n");
            for(i=0;i<n;i++)
            {
                T[i]=T[i]+T[i-1]-1;
                if(T[i]<0)
                    T[i]=0;
                printf("%.0f\t\t%.3f\n",q.que[i],T[i]);
            }
            printf("\n\nWaiting time for 2 tellers : \n");
            T[0]=T[1]=0;
            for(i=0,j=2;i<n;i++,j++)
            {
                t=q.que[i]/10;
                if(t<1)
                    t=1;
                    T[j]=t;
                i++;
                j++;
                t=q.que[i]/10;
                if(t<1)
                    t=1;
                T[j]=t;
            }
            printf("\n\nJobs completed by teller 1 : ");
            for(i=0;i<n;i=i+2)
                printf("%.0f ",q.que[i]);
            printf("\n\nJobs completed by teller 2 : ");
            for(i=1;i<n;i=i+2)
                printf("%.0f ",q.que[i]);
            printf("\n\nJob\t\tWaiting time(in minutes)\n");
            for(i=0;i<n;i++)
            {
                T[i]=T[i]+T[i-2]-2;
                if(T[i]<0)
                    T[i]=0;
                printf("%.0f\t\t%.3f\n",q.que[i],T[i]);
            }
    return 0;
}
