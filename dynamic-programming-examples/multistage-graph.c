// The Multistage Graph focuses on finding the shortest (or longest) path from a source node to a sink node in a graph divided into multiple stages.

#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define N 9      // Total number of nodes
#define STAGES 4 // Total stages

// Function to find the shortest path in a multistage graph
void multistageShortestPath(int graph[N][N], int stages, int n)
{
    int cost[N]; // Minimum cost to reach the sink
    int path[N]; // Stores the next node in the optimal path

    // Base case: cost of the sink is 0
    cost[n - 1] = 0;

    // Compute costs for all nodes from sink to source
    for (int i = n - 2; i >= 0; i--)
    {
        int minCost = INF;
        int nextNode = -1;

        // Check all neighbors of node i
        for (int j = i + 1; j < n; j++)
        {
            if (graph[i][j] != INF && graph[i][j] + cost[j] < minCost)
            {
                minCost = graph[i][j] + cost[j];
                nextNode = j;
            }
        }

        cost[i] = minCost;
        path[i] = nextNode;
    }

    // Print the shortest path
    printf("Shortest Path: ");
    int currentNode = 0;
    printf("%d", currentNode);

    while (currentNode != n - 1)
    {
        currentNode = path[currentNode];
        printf(" -> %d", currentNode);
    }
    printf("\n");

    // Print the minimum cost
    printf("Minimum Cost: %d\n", cost[0]);
}

int main()
{
    // Graph represented as an adjacency matrix
    int graph[N][N] = {
        {INF, 2, 1, 3, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, 2, 3, INF, INF, INF},
        {INF, INF, INF, INF, 1, 1, 3, INF, INF},
        {INF, INF, INF, INF, INF, 2, 2, 1, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, 3},
        {INF, INF, INF, INF, INF, INF, INF, INF, 2},
        {INF, INF, INF, INF, INF, INF, INF, INF, 4},
        {INF, INF, INF, INF, INF, INF, INF, INF, 2},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF}};

    // Solve the multistage graph problem
    multistageShortestPath(graph, STAGES, N);

    return 0;
}

// Time complexity: O(N^2) for adjacency matrix
// Space complexity: O(N) for cost and path arrays
