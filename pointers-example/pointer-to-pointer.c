#include <stdio.h>

int main()
{
    int x = 10;
    int *ptr = &x;         // Pointer to x
    int **ptrToPtr = &ptr; // Pointer to the pointer

    printf("Value of x: %d\n", x);
    printf("Value of x via ptr: %d\n", *ptr);
    printf("Value of x via ptrToPtr: %d\n", **ptrToPtr);

    return 0;
}
