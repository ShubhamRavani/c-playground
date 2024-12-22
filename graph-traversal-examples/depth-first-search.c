#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Graph adjacency matrix
int graph[MAX_VERTICES][MAX_VERTICES];

// DFS algorithm using recursion
void dfs(int vertex, int visited[], int vertices)
{
    // Mark the current node as visited and print it
    visited[vertex] = 1;
    printf("%d ", vertex);

    // Visit all the unvisited neighbors
    for (int i = 0; i < vertices; i++)
    {
        if (graph[vertex][i] == 1 && !visited[i])
        {
            dfs(i, visited, vertices);
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

    printf("DFS traversal starting from vertex %d: ", startVertex);

    // Array to keep track of visited vertices
    int visited[MAX_VERTICES] = {0};

    // Perform DFS traversal
    dfs(startVertex, visited, vertices);

    return 0;
}
