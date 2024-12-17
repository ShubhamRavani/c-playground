#include <stdio.h>
#include <stdlib.h>

// Min-Heap structure
typedef struct
{
    int *array;
    int size;
    int capacity;
} MinHeap;

// Function to create a min-heap
MinHeap *createMinHeap(int capacity)
{
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->array = (int *)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    return minHeap;
}

// Function to swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function to maintain the min-heap property
void heapify(MinHeap *minHeap, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeap->size && minHeap->array[left] < minHeap->array[smallest])
        smallest = left;

    if (right < minHeap->size && minHeap->array[right] < minHeap->array[smallest])
        smallest = right;

    if (smallest != index)
    {
        swap(&minHeap->array[index], &minHeap->array[smallest]);
        heapify(minHeap, smallest);
    }
}

// Function to insert an element into the min-heap
void insertMinHeap(MinHeap *minHeap, int value)
{
    if (minHeap->size == minHeap->capacity)
    {
        printf("Heap is full!\n");
        return;
    }

    int i = minHeap->size++;
    minHeap->array[i] = value;

    // Fix the min-heap property
    while (i > 0 && minHeap->array[(i - 1) / 2] > minHeap->array[i])
    {
        swap(&minHeap->array[(i - 1) / 2], &minHeap->array[i]);
        i = (i - 1) / 2;
    }
}

// Function to extract the minimum element from the min-heap
int extractMin(MinHeap *minHeap)
{
    if (minHeap->size <= 0)
        return -1;

    if (minHeap->size == 1)
        return minHeap->array[--minHeap->size];

    int root = minHeap->array[0];
    minHeap->array[0] = minHeap->array[--minHeap->size];
    heapify(minHeap, 0);

    return root;
}

// Function to calculate the minimum cost of merging files
int optimalMerge(int files[], int n)
{
    MinHeap *minHeap = createMinHeap(n);

    // Insert all file sizes into the min-heap
    for (int i = 0; i < n; i++)
    {
        insertMinHeap(minHeap, files[i]);
    }

    int totalCost = 0;

    // Merge files until only one file is left
    while (minHeap->size > 1)
    {
        // Extract the two smallest files
        int first = extractMin(minHeap);
        int second = extractMin(minHeap);

        // Calculate the cost of merging them
        int mergeCost = first + second;
        totalCost += mergeCost;

        // Insert the merged file back into the heap
        insertMinHeap(minHeap, mergeCost);
    }

    // Free the memory used by the min-heap
    free(minHeap->array);
    free(minHeap);

    return totalCost;
}

int main()
{
    int n;
    printf("Enter the number of files: ");
    scanf("%d", &n);

    int files[n];
    printf("Enter the sizes of the files:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &files[i]);
    }

    int minimumCost = optimalMerge(files, n);
    printf("Minimum cost of merging the files: %d\n", minimumCost);

    return 0;
}
