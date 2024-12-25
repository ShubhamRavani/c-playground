#include <stdio.h>
#include <limits.h>

#define MAX 100

// Function to calculate the minimum multiplication cost
int matrixChainOrder(int p[], int n)
{
    int dp[MAX][MAX];

    for (int i = 1; i < n; i++)
    {
        dp[i][i] = 0;
    }

    for (int length = 2; length < n; length++)
    {
        for (int i = 1; i < n - length + 1; i++)
        {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                dp[i][j] = (cost < dp[i][j]) ? cost : dp[i][j];
            }
        }
    }

    return dp[1][n - 1];
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Minimum multiplication cost: %d\n", matrixChainOrder(arr, n));
    return 0;
}
