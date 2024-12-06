#include <stdio.h>

int main()
{
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    printf("Element at (0, 0): %d\n", matrix[0][0]);
    printf("Element at (1, 2): %d\n", matrix[1][2]);

    return 0;
}
