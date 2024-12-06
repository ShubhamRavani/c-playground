#include <stdio.h>

int main()
{
    // Declaration and Initialization
    int array[2][3][4] = {
        {
            {1, 2, 3, 4},   // 1st row of 1st 2D array
            {5, 6, 7, 8},   // 2nd row of 1st 2D array
            {9, 10, 11, 12} // 3rd row of 1st 2D array
        },
        {
            {13, 14, 15, 16}, // 1st row of 2nd 2D array
            {17, 18, 19, 20}, // 2nd row of 2nd 2D array
            {21, 22, 23, 24}  // 3rd row of 2nd 2D array
        }};

    // Accessing elements
    printf("Element at [0][0][0]: %d\n", array[0][0][0]); // 1
    printf("Element at [1][2][3]: %d\n", array[1][2][3]); // 24

    // Printing all elements
    printf("\nAll elements in the 3D array:\n");
    for (int i = 0; i < 2; i++)
    { // Loop over depth
        for (int j = 0; j < 3; j++)
        { // Loop over rows
            for (int k = 0; k < 4; k++)
            { // Loop over columns
                printf("array[%d][%d][%d] = %d\n", i, j, k, array[i][j][k]);
            }
        }
    }

    return 0;
}
