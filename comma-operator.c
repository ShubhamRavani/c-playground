#include <stdio.h>

int main()
{
    int a, b;
    a = (2, 3, 4);
    b = 2, 3, 4;

    printf("%d, %d\n", a, b);

    int m, n, o, p;
    p = (m = 1, n = 2, o = 3, m + n + o);
    printf("Result = %d\n", p);

    return 0;
}
