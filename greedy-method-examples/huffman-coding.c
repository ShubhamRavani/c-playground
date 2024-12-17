#include <stdio.h>
#include <stdlib.h>

// Node structure for the Huffman tree
typedef struct Node
{
    char character;
    int frequency;
    struct Node *left, *right;
} Node;

// Min-Heap structure
typedef struct MinHeap
{
    int size;
    int capacity;
    Node **array;
} MinHeap;

// Function to create a new node
Node *createNode(char character, int frequency)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a min-heap
MinHeap *createMinHeap(int capacity)
{
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (Node **)malloc(capacity * sizeof(Node *));
    return minHeap;
}

// Function to swap two min-heap nodes
void swapNodes(Node **a, Node **b)
{
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function to maintain the min-heap property
void heapify(MinHeap *minHeap, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;

    if (smallest != index)
    {
        swapNodes(&minHeap->array[index], &minHeap->array[smallest]);
        heapify(minHeap, smallest);
    }
}

// Function to check if the size of the heap is 1
int isSizeOne(MinHeap *minHeap)
{
    return (minHeap->size == 1);
}

// Function to extract the minimum value node from the heap
Node *extractMin(MinHeap *minHeap)
{
    Node *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[--minHeap->size];
    heapify(minHeap, 0);
    return temp;
}

// Function to insert a new node into the heap
void insertMinHeap(MinHeap *minHeap, Node *node)
{
    minHeap->array[minHeap->size] = node;
    int i = minHeap->size++;

    while (i && minHeap->array[i]->frequency < minHeap->array[(i - 1) / 2]->frequency)
    {
        swapNodes(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to build a min-heap
MinHeap *buildMinHeap(char characters[], int frequencies[], int size)
{
    MinHeap *minHeap = createMinHeap(size);

    for (int i = 0; i < size; i++)
        minHeap->array[i] = createNode(characters[i], frequencies[i]);

    minHeap->size = size;

    for (int i = (minHeap->size - 2) / 2; i >= 0; i--)
        heapify(minHeap, i);

    return minHeap;
}

// Function to build the Huffman tree
Node *buildHuffmanTree(char characters[], int frequencies[], int size)
{
    Node *left, *right, *top;

    MinHeap *minHeap = buildMinHeap(characters, frequencies, size);

    while (!isSizeOne(minHeap))
    {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = createNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

// Function to print the Huffman codes
void printCodes(Node *root, int code[], int top)
{
    if (root->left)
    {
        code[top] = 0;
        printCodes(root->left, code, top + 1);
    }

    if (root->right)
    {
        code[top] = 1;
        printCodes(root->right, code, top + 1);
    }

    if (!root->left && !root->right)
    {
        printf("%c: ", root->character);
        for (int i = 0; i < top; i++)
            printf("%d", code[i]);
        printf("\n");
    }
}

// Huffman Coding function
void huffmanCoding(char characters[], int frequencies[], int size)
{
    Node *root = buildHuffmanTree(characters, frequencies, size);

    int code[100], top = 0;
    printCodes(root, code, top);
}

int main()
{
    int n;
    printf("Enter the number of characters: ");
    scanf("%d", &n);

    char characters[n];
    int frequencies[n];

    printf("Enter the characters:\n");
    for (int i = 0; i < n; i++)
    {
        getchar(); // Clear newline from input buffer
        scanf("%c", &characters[i]);
    }

    printf("Enter the frequencies:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &frequencies[i]);
    }

    printf("\nHuffman Codes:\n");
    huffmanCoding(characters, frequencies, n);

    return 0;
}
