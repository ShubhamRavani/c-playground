#include <stdio.h>

int main()
{
    int numbers[5] = {1, 2, 3, 4, 5};

    // Printing all elements using a loop
    for (int i = 0; i < 5; i++)
    {
        printf("Element at index %d: %d\n", i, numbers[i]);
    }

    return 0;
}
