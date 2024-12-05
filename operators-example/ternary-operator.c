// ternary operator have 3 operands
// condition ? expression1 : expression2
// if condition is true then expression1 is executed
// if condition is false then expression2 is executed

#include <stdio.h>

int main()
{
    int a = 10;
    int b = 20;
    int c = 0;

    c = (a > b) ? a : b;
    printf("c = %d\n", c);

    c = (a < b) ? a : b;
    printf("c = %d\n", c);

    return 0;
}
