/*{0,50,45,10,0},
{0,0,10,15,0},
{0,0,0,0,30},
{20,0,0,0,15},
{0,20,35,0,0},*/
#include<stdio.h>
#define MAX 100
#include<stdbool.h>
#define INF 99999

int n; //number of vertices
int dist[MAX]; //array to store shortest distance
int prev[MAX]; //array to store previous vertex
bool visited[MAX]; //array to mark visited vertices
int graph[MAX][MAX]; //adjacency matrix to represent the graph

//function to find the vertex with minimum distance
int minDistance() {
    int min = INF, min_index;
    for (int v = 0; v < n; v++)
        if (visited[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

//function to implement Dijkstra's algorithm
void dijkstra(int src) {
    for (int i = 0; i < n; i++)
        dist[i] = INF, visited[i] = false;
    dist[src] = 0;
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance();
        visited[u] = true;
        for (int v = 0; v < n; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v], prev[v] = u;
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    dijkstra(src);
    printf("Shortest distance from vertex %d:\n", src);
    for (int i = 0; i < n; i++)
        printf("%d - %d\n", i, dist[i]);
    return 0;
}
