#include <stdio.h>

int main()
{
    int x = 10;
    float y = 5.5;

    void *ptr; // Void pointer

    ptr = &x;                                // Point to an integer
    printf("Value of x: %d\n", *(int *)ptr); // Cast to int pointer and dereference

    ptr = &y;                                    // Point to a float
    printf("Value of y: %.2f\n", *(float *)ptr); // Cast to float pointer and dereference

    return 0;
}
