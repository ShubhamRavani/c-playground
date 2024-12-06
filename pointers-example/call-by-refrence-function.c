#include <stdio.h>

void modifyValue(int *x)
{
    *x = 20;
    printf("Inside modifyValue: *x = %d\n", *x);
}

int main()
{
    int a = 10;
    printf("Before modifyValue: a = %d\n", a);
    modifyValue(&a);
    printf("After modifyValue: a = %d\n", a);
    return 0;
}
