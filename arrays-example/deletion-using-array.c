#include <stdio.h>

void deleteElement(int arr[], int *size, int position)
{
    if (position >= *size || position < 0)
    {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements to the left
    for (int i = position; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    (*size)--; // Decrease the size
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5};
    int size = 5;

    printf("Original array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    deleteElement(arr, &size, 2); // Delete element at position 2

    printf("Array after deletion: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
