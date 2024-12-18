#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100
#define INF INT_MAX

// Function to find the vertex with the minimum key value that is not yet included in MST
int minKey(int key[], bool mstSet[], int vertices)
{
    int min = INF, minIndex;

    for (int v = 0; v < vertices; v++)
        if (!mstSet[v] && key[v] < min)
        {
            min = key[v];
            minIndex = v;
        }

    return minIndex;
}

// Function to print the constructed MST
void printMST(int parent[], int graph[MAX][MAX], int vertices)
{
    printf("Edge \tWeight\n");
    int totalWeight = 0;

    for (int i = 1; i < vertices; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }

    printf("Total weight of MST: %d\n", totalWeight);
}

// Function to construct and print the MST using Prim's Algorithm
void primMST(int graph[MAX][MAX], int vertices)
{
    int parent[MAX];  // Array to store the constructed MST
    int key[MAX];     // Key values to pick the minimum weight edge
    bool mstSet[MAX]; // To track vertices included in MST

    // Initialize all keys as infinite and mstSet as false
    for (int i = 0; i < vertices; i++)
    {
        key[i] = INF;
        mstSet[i] = false;
    }

    // Start with the first vertex
    key[0] = 0;     // Make key 0 so this vertex is picked first
    parent[0] = -1; // First node is the root of MST

    // The MST will have vertices-1 edges
    for (int count = 0; count < vertices - 1; count++)
    {
        int u = minKey(key, mstSet, vertices); // Pick the minimum key vertex
        mstSet[u] = true;                      // Include the picked vertex in MST

        // Update key and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < vertices; v++)
        {
            // Update key[v] if graph[u][v] is smaller and v is not in MST
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph, vertices);
}

int main()
{
    int vertices;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[MAX][MAX];
    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, vertices);

    return 0;
}
