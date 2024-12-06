#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to display the circular linked list
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Function to insert a node at the end
struct Node *insertAtEnd(struct Node *head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }

    struct Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    return head;
}

// Function to delete a node by value
struct Node *deleteNode(struct Node *head, int value)
{
    if (head == NULL)
        return NULL;

    struct Node *temp = head;
    struct Node *prev = NULL;

    do
    {
        if (temp->data == value)
        {
            if (prev == NULL)
            { // Deleting the head node
                struct Node *last = head;
                while (last->next != head)
                {
                    last = last->next;
                }

                if (head == head->next)
                { // Single node case
                    free(head);
                    return NULL;
                }

                last->next = head->next;
                free(head);
                return last->next;
            }
            else
            { // Deleting a non-head node
                prev->next = temp->next;
                free(temp);
                return head;
            }
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    return head;
}

int main()
{
    struct Node *head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    display(head);

    head = deleteNode(head, 20);
    display(head);

    return 0;
}
