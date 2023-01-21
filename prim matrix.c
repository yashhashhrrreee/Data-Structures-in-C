#include<stdio.h>
#include<stdlib.h>
#define infinity 9999
#define MAX 20

int G[MAX][MAX],span[MAX][MAX],n;
int prims();
int main()
{
    int i,j,to_cost;
    printf("Enter the number of Vertices:");
    scanf("%d",&n);
    printf("\nEnter the adjacency Matrix:");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%d",G[i][j]);
    to_cost=prims();
    printf("\nSpanning tree matrix:\n");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
        printf("%d\t",span[i][j]);
    }
printf("\n\nTotal cost of Spanning tree=%d",to_cost);
return 0;
}
int prims()
{
    int cost[MAX][MAX];
    int u,v,min_dis,dis[MAX],from[MAX];
    int visited[MAX],no_edge,i,min_cost,j;
    //create cost matrix,span matrix
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    {
        if(G[i][j]==0)
            cost[i][j]=infinity;
        else
            cost[i][j]=G[i][j];
        span[i][j]=0;
    }
    //initialize visited matrix,distance,from matrix
    dis[0]=0;
    visited[0]=1;
    for(i=1;i<n;i++)
    {
        dis[i]=cost[0][i];
        from[i]=0;
        visited[i]=0;
    }
    min_cost=0;
    no_edge=n-1;//number of edges
    while(no_edge>0)
    {
        min_dis=infinity;
        for(i=1;i<n;i++)
            if(visited[i]==0 && dis[i]<min_dis)
        {
            v=i;
            min_dis=dis[i];
        }
        u=from[v];
        span[u][v]=dis[v];
        span[v][u]=dis[v];
        no_edge--;
        visited[v]=-1;
        //update the distance array or matrix
        for(i=1;i<n;i++)
            if(visited[i]==0 && cost[i][v]<dis[i])
        {
            dis[i]=cost[i][v];
            from[i]=v;
        }
        min_cost=min_cost+cost[u][v];
    }
    return(min_cost);
}
