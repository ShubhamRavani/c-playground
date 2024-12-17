#include <stdio.h>

// Function to find the maximum of two numbers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack Problem
void knapsack(int n, int weights[], int values[], int capacity)
{
    int dp[n + 1][capacity + 1];

    // Build the Dynamic Programming table
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0; // Base case: no items or no capacity
            }
            else if (weights[i - 1] <= w)
            {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The maximum value is stored in dp[n][capacity]
    printf("Maximum value that can be carried: %d\n", dp[n][capacity]);

    // Retrieve the items included in the knapsack
    int w = capacity;
    printf("Items included:\n");
    for (int i = n; i > 0 && w > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            printf("Item %d (Weight: %d, Value: %d)\n", i, weights[i - 1], values[i - 1]);
            w -= weights[i - 1];
        }
    }
}

int main()
{
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];

    printf("Enter the weights and values of the items:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &weights[i]);
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &values[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    knapsack(n, weights, values, capacity);

    return 0;
}
