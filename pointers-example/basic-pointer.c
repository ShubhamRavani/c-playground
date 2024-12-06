#include <stdio.h>

int main()
{
    int x = 10;
    int *ptr = &x; // ptr holds the address of x.

    printf("Address of x: %p\n", &x);            // Prints the address of x.
    printf("Address stored in ptr: %p\n", ptr);  // Same as &x.
    printf("Value of x using *ptr: %d\n", *ptr); // Dereference ptr to get x.

    // Modify x using the pointer
    *ptr = 20;
    printf("Modified value of x: %d\n", x); // Now x is 20.

    return 0;
}
