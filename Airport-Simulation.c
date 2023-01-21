/* Write a program which simulates the operation of a busy  
  airport which has only two runways to handle all takeoffs and landings.  
  You may assume that each takeoff or landing takes    15 minutes to complete. 
  One runway request is made during each five minute time interval and likelihood of landing
  request is the same as for takeoff.   Priority is given to  planes requesting a landing.
  If a request cannot be honored it is added to a takeoff or landing queue.   
  Your program should simulate 120 minutes of activity at the airport.  
  Each request for runway clearance should be time-stamped and added to the appropriate queue.
  The output from your program should include the final queue contents, the number of take offs completed,
  the number of landings completed, and the average number of minutes spent in each queue.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#define MAX 20


struct plane
{
    int id;
    int tm;
};

struct queue
{
    int count;
    int front;
    int rear;
    struct plane p[MAX];
};

struct runway
{
    struct queue takeoff;
    struct queue landing;
    struct queue* lp;
    struct queue* tp;
};


struct airport
{
    struct runway runway1;
    struct runway runway2;
    struct runway* r1;
    struct runway* r2;
    struct queue ldwait;
    struct queue tfwait;
    struct queue* pl;
    struct queue* pt;
    int landwait, takeoffwait;
    int nland, nplanes, ntakeoff;
};

void initqueue(struct queue*);
void enqueue(struct queue*, struct plane);
struct plane dequeue(struct queue*);
int size(struct queue*);
int isempty(struct queue);
int isfull(struct queue);
void initairport(struct airport*);
void initrunway(struct runway*);
struct plane newplane(struct airport*, int);
void land(struct airport*, int, int);
void fly(struct airport*, int, int);
void conclude(struct airport*);
int randomize(struct airport*);


void initqueue(struct queue* pq)
{
    pq->count = 0;
    pq->front = 0;
    pq->rear = -1;
}

void enqueue(struct queue* pq, struct plane item)
{
    if (pq->count >= MAX)
    {
        printf("\nQueue is full.\n");
        return;
    }
    (pq->count)++;

    pq->rear = (pq->rear + 1) % MAX;
    pq->p[pq->rear] = item;
}

struct plane dequeue(struct queue* pq)
{
    struct plane p1;

    if (pq->count <= 0)
    {
        printf("\nQueue is empty.\n");
        p1.id = 0;
        p1.tm = 0;
    }
    else
    {
        (pq->count)--;
        p1 = pq->p[pq->front];
        pq->front = (pq->front + 1) % MAX;
    }
    return p1;
}

int size(struct queue* q)
{
    return q->count;
}

int isEmpty(struct queue q)
{
    return (q.count <= 0);
}

int isFull(struct queue q)
{
    return (q.count >= MAX);
}


void initrunway(struct runway* rn)
{
    initqueue(&(rn->landing));
    initqueue(&(rn->takeoff));
    rn->lp = &(rn->landing);
    rn->tp = &(rn->takeoff);
}

void initairport(struct airport* ap)
{
    initqueue(&(ap->ldwait));
    initqueue(&(ap->tfwait));

    ap->pl = &(ap->ldwait);
    ap->pt = &(ap->tfwait);

    initrunway(&(ap->runway1));
    initrunway(&(ap->runway2));
    ap->r1 = &(ap->runway1);
    ap->r2 = &(ap->runway2);

    ap->nplanes = ap->nland = ap->ntakeoff = 0;
    ap->landwait = ap->takeoffwait = 0;
}


struct plane newplane(struct airport* ap, int curtime)
{
    struct plane pln;
    pln.id=++(ap->nplanes);
    pln.tm=curtime;

    return pln;
}


void land(struct airport* ap, int curtime,int runway)
{
    struct plane pln=dequeue(ap->pl);

    if(runway==1)
        enqueue(ap->r1->lp,pln);
    else
        enqueue(ap->r2->lp,pln);

    int wait;

    wait = curtime - pln.tm;
    printf("\n%d: Plane %d landed ", curtime, pln.id);
    printf("in %d minutes \n", wait);
    (ap->nland)++;
    (ap->landwait) += wait;
}

void fly(struct airport* ap, int curtime,int runway)
{
    struct plane pln=dequeue(ap->pt);

    if(runway==1)
        enqueue(ap->r1->tp,pln);
    else
        enqueue(ap->r2->tp,pln);

    int wait;

    wait = curtime - pln.tm;
    printf("\n%d: Plane %d took off ", curtime, pln.id);
    printf("in %d units \n", wait);
    (ap->ntakeoff)++;
    (ap->takeoffwait) += wait;
}


void conclude(struct airport* ap)
{
    int i;
    struct plane pln;
    printf("\nSimulation has concluded.\n");
    printf("Total number of planes processed: %d\n", ap->nplanes);
    printf("Number of planes landed: %d\n", ap->nland);
    printf("Number of planes taken off: %d\n", ap->ntakeoff);

    if (ap->nland > 0)
        printf("Average wait time to land: %lf \n", ((double)ap->landwait / ap->nland));

    if (ap->ntakeoff > 0)
        printf("Average wait time to take off: %lf \n", ((double)ap->takeoffwait / ap->ntakeoff));

    printf("\nRunway 1.....\n");
    printf("Landed:\n");
    printf("\tPlane ID \t|   Unit of time of request\n");

    for(i=0 ; i<size(ap->r1->lp) ; i++)
    {
        pln=dequeue(ap->r1->lp);
        printf("\t%d       \t|   %d\n",pln.id,pln.tm);
    }

    printf("\nTaken-off:\n");
    printf("\tPlane ID \t|   Unit of time of request\n");

    for(i=0 ; i<size(ap->r1->tp) ; i++)
    {
        pln=dequeue(ap->r1->tp);
        printf("\t%d       \t|   %d\n",pln.id,pln.tm);
    }

    printf("\nRunway 2.....\n");
    printf("Landed:\n");
    printf("\tPlane ID \t|   Unit of time of request\n");

    for(i=0 ; i<size(ap->r2->lp) ; i++)
    {
        pln=dequeue(ap->r2->lp);
        printf("\t%d       \t|   %d\n",pln.id,pln.tm);
    }

    printf("\nTaken-off:\n");
    printf("\tPlane ID \t|   Unit of time of request\n");

    for(i=0 ; i<size(ap->r2->tp) ; i++)
    {
        pln=dequeue(ap->r2->tp);
        printf("\t%d       \t|   %d\n",pln.id,pln.tm);
    }

    printf("\nRemaining in waiting queues.....\n");
    printf("Landing wait queue:\n");
    printf("\tPlane ID \t|   Unit of time of request\n");

    for(i=0 ; i<size(ap->pl) ; i++)
    {
        pln=dequeue(ap->pl);
        printf("\t%d       \t|   %d\n",pln.id,pln.tm);
    }

    printf("\nTakeoff wait queue:\n");
    printf("\tPlane ID \t|   Unit of time of request\n");

    for(i=0 ; i<size(ap->pt) ; i++)
    {
        pln=dequeue(ap->pt);
        printf("\t%d       \t|   %d\n",pln.id,pln.tm);
    }

}


int randomize(struct airport* ap)
{

    int action=rand()%2;

    switch (action)
    {
    case 0:
        printf("\nPlane %d ready to land.\n", ap->nplanes);
        break;

    case 1:
        printf("\nPlane %d ready to take off.\n", ap->nplanes);
        break;
    }
    return action;
}

void main()
{
    struct airport a;
    int i, req;
    struct plane pln;

    srand(time(NULL));
    initairport(&a);

    printf("Simulation of an airport with two runways.....\n");
    printf("The simulation lasts 120 units of time.\nThe time indicates the number of units after beginning of simulation.\nLanding requests are given priority and requests are usually serviced by runway 1 first.\n");

    for(i=1 ; i<=120 ; i++)
    {

        if(i==0 || i%5==0)
        {
            pln=newplane(&a,i);
            req=randomize(&a);
            if(req==0)
                enqueue(a.pl,pln);
            else
                enqueue(a.pt,pln);

        }

        if(i%15==0)
        {
            if(size(a.pl))  //runway1
                land(&a,i,1);
            else if(size(a.pt))
                fly(&a,i,1);

            if(size(a.pl))  //runway2
                land(&a,i,2);
            else if(size(a.pt))
                fly(&a,i,2);
        }


    }

    conclude(&a);


}
