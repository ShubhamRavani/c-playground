#include <stdio.h>
#include <string.h>
#define MAX 100

// Function to find the length of LCS
int lcs(char *s1, char *s2, int m, int n)
{
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    return dp[m][n];
}

int main()
{
    char s1[MAX] = "AGGTAB";
    char s2[MAX] = "GXTXAYB";
    int m = strlen(s1);
    int n = strlen(s2);

    printf("Length of LCS is %d\n", lcs(s1, s2, m, n));
    return 0;
}
