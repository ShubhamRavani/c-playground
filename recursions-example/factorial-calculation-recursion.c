#include <stdio.h>

// Recursive function to calculate factorial
int factorial(int number)
{
    if (number == 0)
    { // Base case
        return 1;
    }
    else
    {
        return number * factorial(number - 1); // Recursive case
    }
}

int main()
{
    int number = 5;
    printf("Factorial of %d is %d\n", number, factorial(number));
    return 0;
}
