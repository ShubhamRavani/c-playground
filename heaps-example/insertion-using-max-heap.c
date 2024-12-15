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

    insert(heap, 10);
    insert(heap, 20);
    insert(heap, 5);
    insert(heap, 30);
    insert(heap, 15);

    printHeap(heap);

    return 0;
}
