#include <stdio.h>
#include <stdlib.h>

void add(int n, int A[n][n], int B[n][n], int C[n][n])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int n, int A[n][n], int B[n][n], int C[n][n])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int n, int A[n][n], int B[n][n], int C[n][n])
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    // Allocate submatrices
    int(*A11)[k] = malloc(sizeof(int[k][k]));
    int(*A12)[k] = malloc(sizeof(int[k][k]));
    int(*A21)[k] = malloc(sizeof(int[k][k]));
    int(*A22)[k] = malloc(sizeof(int[k][k]));

    int(*B11)[k] = malloc(sizeof(int[k][k]));
    int(*B12)[k] = malloc(sizeof(int[k][k]));
    int(*B21)[k] = malloc(sizeof(int[k][k]));
    int(*B22)[k] = malloc(sizeof(int[k][k]));

    int(*M1)[k] = malloc(sizeof(int[k][k]));
    int(*M2)[k] = malloc(sizeof(int[k][k]));
    int(*M3)[k] = malloc(sizeof(int[k][k]));
    int(*M4)[k] = malloc(sizeof(int[k][k]));
    int(*M5)[k] = malloc(sizeof(int[k][k]));
    int(*M6)[k] = malloc(sizeof(int[k][k]));
    int(*M7)[k] = malloc(sizeof(int[k][k]));

    int(*temp1)[k] = malloc(sizeof(int[k][k]));
    int(*temp2)[k] = malloc(sizeof(int[k][k]));

    // Divide matrices into quadrants
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    // Calculate M1 to M7
    add(k, A11, A22, temp1);
    add(k, B11, B22, temp2);
    strassen(k, temp1, temp2, M1);

    add(k, A21, A22, temp1);
    strassen(k, temp1, B11, M2);

    subtract(k, B12, B22, temp2);
    strassen(k, A11, temp2, M3);

    subtract(k, B21, B11, temp2);
    strassen(k, A22, temp2, M4);

    add(k, A11, A12, temp1);
    strassen(k, temp1, B22, M5);

    subtract(k, A21, A11, temp1);
    add(k, B11, B12, temp2);
    strassen(k, temp1, temp2, M6);

    subtract(k, A12, A22, temp1);
    add(k, B21, B22, temp2);
    strassen(k, temp1, temp2, M7);

    // Combine results into C
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C[i][j + k] = M3[i][j] + M5[i][j];
            C[i + k][j] = M2[i][j] + M4[i][j];
            C[i + k][j + k] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }

    // Free allocated memory
    free(A11);
    free(A12);
    free(A21);
    free(A22);
    free(B11);
    free(B12);
    free(B21);
    free(B22);
    free(M1);
    free(M2);
    free(M3);
    free(M4);
    free(M5);
    free(M6);
    free(M7);
    free(temp1);
    free(temp2);
}

int main()
{
    int n;
    printf("Enter the size of the matrix (power of 2): ");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];

    printf("Enter matrix A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    strassen(n, A, B, C);

    printf("Resultant matrix C:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}
