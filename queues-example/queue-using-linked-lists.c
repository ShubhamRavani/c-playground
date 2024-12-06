#include <stdio.h>
#include <stdlib.h>

// Define a structure for the queue node
struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Enqueue operation
void enqueue(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Queue Overflow!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued to queue.\n", value);
}

// Dequeue operation
void dequeue()
{
    if (front == NULL)
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        struct Node *temp = front;
        printf("%d dequeued from queue.\n", front->data);
        front = front->next;
        if (front == NULL)
            rear = NULL; // Reset rear if the queue becomes empty
        free(temp);
    }
}

// Peek operation
void peek()
{
    if (front == NULL)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Front element: %d\n", front->data);
    }
}

// Display queue elements
void display()
{
    if (front == NULL)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Queue elements: ");
        struct Node *temp = front;
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
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    peek();
    dequeue();
    display();
    return 0;
}
