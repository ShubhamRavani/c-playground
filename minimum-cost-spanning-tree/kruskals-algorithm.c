#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent an edge
typedef struct
{
    int src, dest, weight;
} Edge;

// Structure to represent a graph
typedef struct
{
    int vertices, edges;
    Edge edge[MAX];
} Graph;

// Structure to represent a subset for union-find
typedef struct
{
    int parent, rank;
} Subset;

// Function prototypes
Graph *createGraph(int vertices, int edges);
int compareEdges(const void *a, const void *b);
int find(Subset subsets[], int i);
void unionSet(Subset subsets[], int x, int y);
void KruskalMST(Graph *graph);

int main()
{
    int vertices, edges;

    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    Graph *graph = createGraph(vertices, edges);

    printf("Enter the source, destination, and weight of each edge:\n");
    for (int i = 0; i < edges; i++)
    {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &graph->edge[i].src, &graph->edge[i].dest, &graph->edge[i].weight);
    }

    KruskalMST(graph);

    free(graph);
    return 0;
}

Graph *createGraph(int vertices, int edges)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->edges = edges;
    return graph;
}

int compareEdges(const void *a, const void *b)
{
    Edge *edge1 = (Edge *)a;
    Edge *edge2 = (Edge *)b;
    return edge1->weight - edge2->weight;
}

int find(Subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSet(Subset subsets[], int x, int y)
{
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
    {
        subsets[rootX].parent = rootY;
    }
    else if (subsets[rootX].rank > subsets[rootY].rank)
    {
        subsets[rootY].parent = rootX;
    }
    else
    {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

void KruskalMST(Graph *graph)
{
    int vertices = graph->vertices;
    Edge result[MAX];
    int resultIndex = 0;
    int edgeIndex = 0;

    // Sort edges by weight
    qsort(graph->edge, graph->edges, sizeof(graph->edge[0]), compareEdges);

    // Allocate memory for union-find subsets
    Subset *subsets = (Subset *)malloc(vertices * sizeof(Subset));
    for (int v = 0; v < vertices; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges in the MST is V-1
    while (resultIndex < vertices - 1 && edgeIndex < graph->edges)
    {
        Edge nextEdge = graph->edge[edgeIndex++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // If including this edge does not cause a cycle
        if (x != y)
        {
            result[resultIndex++] = nextEdge;
            unionSet(subsets, x, y);
        }
    }

    // Print the MST
    printf("Edges in the Minimum Spanning Tree:\n");
    int totalWeight = 0;
    for (int i = 0; i < resultIndex; ++i)
    {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        totalWeight += result[i].weight;
    }
    printf("Total weight of MST: %d\n", totalWeight);

    free(subsets);
}
