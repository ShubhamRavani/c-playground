#include <stdio.h>

// Recursive function to find nth Fibonacci number
int fibonacci(int number)
{
    if (number == 0)
    { // Base case
        return 0;
    }
    else if (number == 1)
    { // Base case
        return 1;
    }
    else
    {
        return fibonacci(number - 1) + fibonacci(number - 2); // Recursive case
    }
}

int main()
{
    int terms = 10;
    for (int i = 0; i < terms; i++)
    {
        printf("%d ", fibonacci(i));
    }
    return 0;
}
