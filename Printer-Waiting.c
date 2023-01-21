/*An operating system assigns job to print queues based on the number of pages 
to be printed (1 to 50 pages).  
You may assume that the system printers are able to print 10 page per minute.  
Smaller print jobs are printed before larger print jobs and print jobs are processed
from a single print queue implemented as a priority queue).  
The system administrators would like to compare
the time required to process a set of print jobs using 1, 2, or 3 system printers. 
Write a program which simulates processing 100 print jobs of varying lengths using either 1, 2, or 3 printers.  
Assume that a print request is made every minute and that the number of pages to print varies from 1 to 50 pages.  
To be fair, you will need to process the same set of print jobs each time you add a printer. 
The output from your program should indicate the order in which the jobs were received, the order in which they were    
printed, and the time required to process the set of print jobs.  
If more than one printer is being used, indicate which printer each job was printed on.*/

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
for(i=q.top;i>0;i--)
{
    if(q.que[i]<=q.que[i-1])
    {
        temp=q.que[i];
        q.que[i]=q.que[i-1];
        q.que[i-1]=temp;
    }
}
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
    int y;
    do
    {
    q.top=-1;
    int np,pjobs[100],i,j;
    float n,t=0,T[100];
    printf("\n\nenter the number of print jobs : ");
    scanf("%f",&n);
    printf("\nenter the number of pages for each job : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&pjobs[i]);
        push(pjobs[i]);
    }
    printf("\nenter the number of printers : ");
    scanf("%d",&np);
    printf("the order in which the jobs were received : \n\n");
    for(i=0;i<n;i++)
        printf("%d ",pjobs[i]);
    printf("\n\nthe order in which the jobs were processed : \n\n");
    for(i=0;i<n;i++)
        printf("%.0f ",q.que[i]);
    switch(np)
    {
    case 1:
        {
            T[0]=0;
            for(i=0,j=1;i<n;i++,j++)
            {
                t=q.que[i]/10;
                if(t<1)
                    t=1;
                T[j]=t;
            }
            printf("\n\njob\t\twaiting time\n");
            for(i=0;i<n;i++)
            {
                T[i]=T[i]+T[i-1]-1;
                if(T[i]<0)
                    T[i]=0;
                printf("%.0f\t\t%.3f\n",q.que[i],T[i]);
            }
            break;
        }
    case 2:
        {
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
            printf("\n\njobs printed by printer 1 : ");
            for(i=0;i<n;i=i+2)
                printf("%.0f ",q.que[i]);
            printf("\n\njobs printed by printer 2 : ");
            for(i=1;i<n;i=i+2)
                printf("%.0f ",q.que[i]);
            printf("\n\njob\t\twaiting time\n");
            for(i=0;i<n;i++)
            {
                T[i]=T[i]+T[i-2]-2;
                if(T[i]<0)
                    T[i]=0;
                printf("%.0f\t\t%.3f\n",q.que[i],T[i]);
            }
            break;
        }
    case 3:
        {
            T[0]=T[1]=T[2]=0;
            for(i=0,j=3;i<n;i++,j++)
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
                i++;
                j++;
                t=q.que[i]/10;
                if(t<1)
                    t=1;
                T[j]=t;
            }
            printf("\n\njobs printed by printer 1 : ");
            for(i=0;i<n;i=i+3)
                printf("%.0f ",q.que[i]);
            printf("\n\njobs printed by printer 2 : ");
            for(i=1;i<n;i=i+3)
                printf("%.0f ",q.que[i]);
            printf("\n\njobs printed by printer 3 : ");
            for(i=2;i<n;i=i+3)
                printf("%.0f ",q.que[i]);
            printf("\n\njob\t\twaiting time\n");
            for(i=0;i<n;i++)
            {
                T[i]=T[i]+T[i-3]-3;
                if(T[i]<0)
                    T[i]=0;
                printf("%.0f\t\t%.3f\n",q.que[i],T[i]);
            }
            break;
        }
    default:
        printf("invalid number of printers");
    }
    printf("\n\ndo you want to continue : 1.YES 2.NO\n");
    scanf("%d",&y);
    }while(y==1);
    return 0;
}