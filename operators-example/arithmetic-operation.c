#include <stdio.h>

int main()
{

    printf("Arithmetic Operations on Integers Value");
    int x = 15, y = 6;

    printf("\nAddition - %d", x + y);
    printf("\nSubtraction - %d", x - y);
    printf("\nMultiplication - %d", x * y);
    printf("\nDivision - %d", x / y);
    printf("\nModulus - %d", x % y);

    printf("\n\nArithmetic Operations on Float Value \n");
    float a = 15.0, b = 6.0;
    printf("Addition - %f", a + b);
    printf("\nSubtraction - %f", a - b);
    printf("\nMultiplication - %f", a * b);
    printf("\nDivision - %f", a / b);
    printf("\nModulus - Not Possible");

    return 0;
}
