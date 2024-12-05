#include <stdio.h>

void modifyValue(int x)
{
    x = 20; // Changes the local copy
    printf("Inside modifyValue: x = %d\n", x);
}

int main()
{
    int a = 10;
    printf("Before modifyValue: a = %d\n", a);
    modifyValue(a);                           // Passes a copy of 'a'
    printf("After modifyValue: a = %d\n", a); // 'a' remains unchanged
    return 0;
}
