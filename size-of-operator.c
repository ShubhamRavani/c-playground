// size of operator is a unary operator that is used to get the size of data types and variables.

#include <stdio.h>

int main()
{
    int a = 10;
    char b = 'A';
    float c = 10.5;
    double d = 10.5;

    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of char: %zu byte\n", sizeof(char));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));

    printf("Size of a: %zu bytes\n", sizeof(a));
    printf("Size of b: %zu byte\n", sizeof(b));
    printf("Size of c: %zu bytes\n", sizeof(c));
    printf("Size of d: %zu bytes\n", sizeof(d));

    return 0;
}
