#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Queue structure for BFS
struct Queue
{
    int items[MAX_VERTICES];
    int front, rear;
};

// Graph adjacency matrix
int graph[MAX_VERTICES][MAX_VERTICES];

// Queue functions
void initQueue(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isQueueEmpty(struct Queue *q)
{
    return q->front == -1;
}

void enqueue(struct Queue *q, int value)
{
    if (q->rear == MAX_VERTICES - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Queue Underflow\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
    {
        q->front = q->rear = -1;
    }
    return item;
}

// BFS algorithm
void bfs(int startVertex, int vertices)
{
    int visited[MAX_VERTICES] = {0};
    struct Queue q;
    initQueue(&q);

    visited[startVertex] = 1;
    enqueue(&q, startVertex);

    while (!isQueueEmpty(&q))
    {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; i++)
        {
            if (graph[currentVertex][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
}

int main()
{
    int vertices, edges, startVertex, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize the graph with zeros
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            graph[i][j] = 0;
        }
    }

    // Take edge input
    for (int i = 0; i < edges; i++)
    {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // For undirected graph
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    printf("BFS traversal starting from vertex %d: ", startVertex);
    bfs(startVertex, vertices);

    return 0;
}
