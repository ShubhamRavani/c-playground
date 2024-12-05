#include <stdio.h>

// Function to add two numbers
int add(int a, int b)
{
    return a + b;
}

int main()
{
    int x = 5, y = 10;
    int sum = add(x, y); // Function call
    printf("Sum: %d\n", sum);
    return 0;
}
