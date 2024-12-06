#include <stdio.h>
#include <stdlib.h>

// Define a structure for the stack node
struct Node
{
    int data;
    struct Node *next;
};

// Initialize the stack as empty
struct Node *top = NULL;

// Push operation
void push(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Stack Overflow!\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack.\n", value);
}

// Pop operation
void pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        struct Node *temp = top;
        printf("%d popped from stack.\n", top->data);
        top = top->next;
        free(temp);
    }
}

// Peek operation
void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Top element: %d\n", top->data);
    }
}

// Display stack elements
void display()
{
    if (top == NULL)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack elements: ");
        struct Node *temp = top;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
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
