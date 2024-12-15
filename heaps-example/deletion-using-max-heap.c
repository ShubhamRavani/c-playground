#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of the heap

// Structure to represent a max-heap
typedef struct MaxHeap
{
    int size;          // Current size of the heap
    int arr[MAX_SIZE]; // Array to store heap elements
} MaxHeap;

// Function to initialize a max-heap
MaxHeap *createHeap()
{
    MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
    heap->size = 0;
    return heap;
}

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to insert a value into the max-heap
void insert(MaxHeap *heap, int value)
{
    if (heap->size == MAX_SIZE)
    {
        printf("Heap is full!\n");
        return;
    }

    // Insert the new value at the end of the heap
    heap->size++;
    int i = heap->size - 1;
    heap->arr[i] = value;

    // Heapify up to restore the max-heap property
    while (i != 0 && heap->arr[(i - 1) / 2] < heap->arr[i])
    {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]); // Swap with parent
        i = (i - 1) / 2;                              // Move to the parent's index
    }
}

// Function to heapify down from a given index
void heapifyDown(MaxHeap *heap, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2; // Right child index

    // Check if the left child is larger than the current largest
    if (left < heap->size && heap->arr[left] > heap->arr[largest])
    {
        largest = left;
    }

    // Check if the right child is larger than the current largest
    if (right < heap->size && heap->arr[right] > heap->arr[largest])
    {
        largest = right;
    }

    // If the largest is not the root, swap and continue heapifying
    if (largest != i)
    {
        swap(&heap->arr[i], &heap->arr[largest]);
        heapifyDown(heap, largest); // Recursively heapify the affected subtree
    }
}

// Function to delete the root from the max-heap
int deleteRoot(MaxHeap *heap)
{
    if (heap->size <= 0)
    {
        printf("Heap is empty!\n");
        return -1;
    }

    int root = heap->arr[0]; // Store the root value

    // Replace root with the last element
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--; // Reduce the size of the heap

    // Heapify down from the root
    heapifyDown(heap, 0);

    return root; // Return the deleted root value
}

// Function to print the heap
void printHeap(MaxHeap *heap)
{
    printf("Heap elements: ");
    for (int i = 0; i < heap->size; i++)
    {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

int main()
{
    MaxHeap *heap = createHeap();

    insert(heap, 50);
    insert(heap, 30);
    insert(heap, 40);
    insert(heap, 10);
    insert(heap, 20);
    insert(heap, 60);

    printf("Initial Heap:\n");
    printHeap(heap);

    // Delete the root
    printf("Deleted Root: %d\n", deleteRoot(heap));

    // Print the heap after deletion
    printf("Heap after deletion:\n");
    printHeap(heap);

    return 0;
}
