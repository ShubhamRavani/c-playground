#include <stdio.h>

// A simple function
void greet()
{
    printf("Hello, World!\n");
}

// Function with parameters
int add(int a, int b)
{
    return a + b;
}

int main()
{
    // Pointer to a function with no parameters
    void (*funcPtr)() = greet;
    funcPtr(); // Call the function via the pointer

    // Pointer to a function with parameters
    int (*addPtr)(int, int) = add;
    int result = addPtr(5, 3); // Call the function via the pointer
    printf("Sum: %d\n", result);

    return 0;
}
