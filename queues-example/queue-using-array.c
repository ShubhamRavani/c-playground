#include <stdio.h>
#define MAX 5 // Define the maximum size of the queue

int queue[MAX];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        if (front == -1)
            front = 0; // Initialize front if the queue was empty
        queue[++rear] = value;
        printf("%d enqueued to queue.\n", value);
    }
}

// Dequeue operation
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        printf("%d dequeued from queue.\n", queue[front++]);
        if (front > rear)
            front = rear = -1; // Reset the queue if empty
    }
}

// Peek operation
void peek()
{
    if (front == -1)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Front element: %d\n", queue[front]);
    }
}

// Display queue elements
void display()
{
    if (front == -1)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
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
