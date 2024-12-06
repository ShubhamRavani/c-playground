#include <stdio.h>

void insertElement(int arr[], int *size, int position, int value)
{
    if (position > *size || position < 0)
    {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements to the right
    for (int i = *size; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[position] = value; // Insert the new element
    (*size)++;             // Update the size
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

    insertElement(arr, &size, 2, 99); // Insert 99 at position 2

    printf("Array after insertion: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
