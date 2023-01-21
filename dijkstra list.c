#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100

struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

struct Graph {
    int numNodes;
    int* dist;
    struct Node** adjList;
};

struct Graph* createGraph(int n) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numNodes = n;
    graph->adjList = (struct Node**)malloc(n * sizeof(struct Node*));
    graph->dist = (int*)malloc(n * sizeof(int));

    int i;
    for (i = 0; i < n; i++) {
        graph->adjList[i] = NULL;
        graph->dist[i] = INT_MAX;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

int minDistance(int* dist, int* visited, int numNodes) {
    int min = INT_MAX, minIndex;
    int i;

    for (i = 0; i < numNodes; i++) {
        if (visited[i] == 0 && dist[i] <= min) {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstra(struct Graph* graph, int src) {
    int* visited = (int*)malloc(graph->numNodes * sizeof(int));
    int i;

    for (i = 0; i < graph->numNodes; i++) {
        visited[i] = 0;
    }

    graph->dist[src] = 0;

    int count;
    for (count = 0; count < graph->numNodes - 1; count++) {
        int u = minDistance(graph->dist, visited, graph->numNodes);
        visited[u] = 1;

        struct Node* temp = graph->adjList[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (!visited[v] && graph->dist[u] != INT_MAX && graph->dist[u] + weight < graph->dist[v]) {
                graph->dist[v] = graph->dist[u] + weight;
            }

            temp = temp->next;
        }
    }
}

int main() {
    int numNodes = 9;
    struct Graph* graph = createGraph(numNodes);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    dijkstra(graph, 0);

    printf("Shortest distances from the source vertex:\n");
    int i;
    for (i = 0; i < numNodes; i++) {
        printf("%d\t\t%d\n", i, graph->dist[i]);
    }

    return 0;
}

