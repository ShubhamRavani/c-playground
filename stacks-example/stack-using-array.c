#include <stdio.h>
#define MAX 5 // Define the maximum size of the stack

int stack[MAX];
int top = -1; // Initialize the stack as empty

// Push operation
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        stack[++top] = value;
        printf("%d pushed to stack.\n", value);
    }
}

// Pop operation
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        printf("%d popped from stack.\n", stack[top--]);
    }
}

// Peek operation
void peek()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Top element: %d\n", stack[top]);
    }
}

// Display stack elements
void display()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    display();
    peek();
    pop();
    display();
    return 0;
}
