#include <stdio.h>
#include <limits.h>

#define MAX 100

// Function to find the minimum number of coins
int minCoins(int coins[], int m, int V)
{
    int dp[V + 1];
    dp[0] = 0;

    for (int i = 1; i <= V; i++)
    {
        dp[i] = INT_MAX;
        for (int j = 0; j < m; j++)
        {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX)
            {
                dp[i] = (dp[i] < 1 + dp[i - coins[j]]) ? dp[i] : 1 + dp[i - coins[j]];
            }
        }
    }

    return dp[V] == INT_MAX ? -1 : dp[V];
}

int main()
{
    int coins[] = {1, 2, 5};
    int m = sizeof(coins) / sizeof(coins[0]);
    int V = 11; // Value to make

    int result = minCoins(coins, m, V);
    if (result != -1)
    {
        printf("Minimum coins required: %d\n", result);
    }
    else
    {
        printf("Not possible to make the amount with given coins\n");
    }

    return 0;
}
