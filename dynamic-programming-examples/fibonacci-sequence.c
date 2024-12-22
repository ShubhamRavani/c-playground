#include <stdio.h>

// Function to calculate Fibonacci numbers using dynamic programming
int fibonacci(int n)
{
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main()
{
    int n = 10; // Find the 10th Fibonacci number
    printf("Fibonacci number at position %d is %d\n", n, fibonacci(n));
    return 0;
}
