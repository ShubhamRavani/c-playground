#include <stdio.h>

int main()
{
    int a = 5;

    printf("Prefix: \n");
    printf("%d\n", ++a);
    printf("%d\n", a);
    printf("%d\n", --a);
    printf("%d\n", a);

    printf("Postfix: \n");
    printf("%d\n", a++);
    printf("%d\n", a);
    printf("%d\n", a--);
    printf("%d\n", a);
}